from enum import Enum

from django.shortcuts import render, redirect
from django.views import View

from django_request_mapping import request_mapping

from ..models import (
    DevicesData
)


class ControlType(str, Enum):
    AUTO = 'auto'
    MANUAL = 'manual'


@request_mapping("/control")
class ControlView(View):
    #@request_mapping("/auto")
    #def auto_control(self, request):
    #    return self._get_control_data(request, ControlType.AUTO)

    @request_mapping("/")
    def manual_control(self, request):
        return self._get_control_data(request, ControlType.MANUAL)

    @staticmethod
    def _get_control_data(request, control_type: ControlType):
        if not request.user.is_authenticated:
            return redirect(f'/{request.LANGUAGE_CODE}/sign_in')

        user = request.user

        last_inits = DevicesData.objects.filter(owner=user.pk).last()
        inits = last_inits.init_data if last_inits is not None else []

        last_sensors = DevicesData.objects.filter(owner=user.pk).last()
        sensors = last_sensors.sensors_data if last_sensors is not None else []

        executors = []
        try:
            last_executors = DevicesData.objects.filter(owner=user.pk).last()

            if last_executors is not None:
                executors.extend(last_executors.executors_data[control_type]['sent'])
                executors.extend(last_executors.executors_data[control_type]['not_sent'])
        except (TypeError, KeyError) as e:
            executors = []

        return render(
            request,
            f'control/{control_type}_control.html',
            context={
                'inits': inits,
                'sensors': sensors,
                'executors': executors
            }
        )
