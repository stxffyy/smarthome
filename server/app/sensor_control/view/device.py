import json

from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth.models import User
from django.utils import timezone
from django.views import View

from django_request_mapping import request_mapping

from ..models import DevicesData


@request_mapping("/device")
class DeviceView(View):
    @request_mapping("/init_sensors/", method='post')
    @csrf_exempt
    def init_sensors(self, request):
        """
        Получаем данные инициализации с wemos и загружаем их в бд
        """

        req = json.loads(request.body.decode("utf-8"))
        try:
            sender = User.objects.get(username=json.dumps(req['user'])[1:-1])
        except User.DoesNotExist:
            print("Send setup for non-existent user")
            return HttpResponse("User does not exist")

        # delete all previous setups from this user
        DevicesData.objects.filter(owner=sender.pk).delete()

        data = {
            'init_data': json.dumps(req['init']),
            'devices_data': [],
            'owner': sender,
            'ip': json.dumps(req['ip']),
            'date_created': timezone.now(),
        }

        d = DevicesData(
            init_data=data['init_data'],
            sensors_data=data['init_data'],
            executors_data=data['init_data'],
            date_created=data['date_created'],
            owner=data['owner'],
            ip=data['ip'],
        )
        d.save()

        return HttpResponse("Sensors init received")

    @request_mapping("/receive_data/", method='post')
    @csrf_exempt
    def receive_data(self, request):
        print("receive_data : ", request.body.decode("utf-8"))
        req = json.loads(request.body.decode("utf-8"))
        try:
            sender = User.objects.get(username=json.dumps(req['user'])[1:-1])
        except User.DoesNotExist:
            print("Receive data from non-existent user")
            return HttpResponse("User does not exist")

        DevicesData.objects.filter(owner=sender.pk).delete()

        # for device in req['data']:
        data = {
            'date_created': timezone.now(),
            'owner': sender.pk,
            'ip': json.dumps(req['ip']),
            'init_data': json.dumps(req['init_data']),
            'devices_data': json.dumps(req['devices_data']),
        }

        s = DevicesData(data)
        s.save()

        return HttpResponse("Only data received")

    @request_mapping("/send_data/", method='post')
    @csrf_exempt
    def send_data(self, request):
        print("send_data : ", request.body.decode("utf-8"))
        req = json.loads(request.body.decode("utf-8"))
        try:
            user = User.objects.get(username=json.dumps(req['user'])[1:-1])
        except User.DoesNotExist:
            print("Send data for non-existent user")
            return HttpResponse("User does not exist")

    @request_mapping("/store_executors/", method='post')
    @csrf_exempt
    def store_executors(self, request):
        user_pk = request.user.pk

        data = json.loads(request.POST.get('data', None))

        is_auto = request.POST.get('is_auto', None)

        # print('Stored executors: ', data, is_auto, request.user.id)
        try:
            dd = DevicesData.objects.filter(owner=user_pk).last()
            ins = dd.init_data
            exs = dd.executors_data

            if len(exs.keys()) == 0:
                exs = {
                    'is_auto': str(is_auto),
                    'manual': {
                        'sent': [],
                        'not_sent': []
                    },
                    'auto': {
                        'sent': [],
                        'not_sent': []
                    }
               }

            ex1, ex2, ex3, ex4 = dict(), dict(), dict(), dict()

            for in_d in ins:
                if in_d['type'] == data['type'] and in_d['port'] == data['port']:
                    ex1 = exs['manual']['sent']
                    ex2 = exs['manual']['not_sent']
                    fl1 = True
                    fl2 = False
                    for i in range(len(ex1)):
                        if ex1[i]['type'] == data['type'] and ex1[i]['port'] == data['port']:
                            del ex1[i]
                            fl1 = False
                    if fl1:
                        for i in range(len(ex2)):
                            if ex2[i]['type'] == data['type'] and ex2[i]['port'] == data['port']:
                                ex2[i] = data
                                fl2 = True
                        if fl2 is False:
                            ex2.append(data)
                    else:
                        ex2.append(data)

                else:
                    ex3 = exs['auto']['sent']
                    ex4 = exs['auto']['not_sent']
                    fl1 = True
                    fl2 = False
                    for i in range(len(ex3)):
                        if ex3[i]['type'] == data['type'] and ex3[i]['port'] == data['port']:
                            del ex3[i]
                            fl1 = False
                    if fl1:
                        for i in range(len(ex4)):
                            if ex4[i]['type'] == data['type'] and ex4[i]['port'] == data['port']:
                                ex4[i] = data
                                fl2 = True
                        if fl2 is False:
                            ex4.append(data)
                    else:
                        ex4.append(data)

            exs['manual']['sent'] = ex1
            exs['manual']['not_sent'] = ex2
            exs['auto']['sent'] = ex3
            exs['auto']['not_sent'] = ex4

            dd = {
                'init_data': dd.init_data,
                'sensors_data': dd.sensors_data,
                'executors_data': exs,
                'date_created': timezone.now(), 'owner_id': user_pk, 'ip': dd.ip
            }

            DevicesData.objects.filter(owner_id=user_pk).delete()
            new_dd = DevicesData(**dd)
            new_dd.save()
        except User.DoesNotExist:
            return HttpResponse("404_save_executors")

        return HttpResponse("Sent data for executors in db")
