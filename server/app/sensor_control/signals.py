from django.db.models.signals import post_save
from django.dispatch import receiver
from channels.layers import get_channel_layer
from asgiref.sync import async_to_sync

from .models import DevicesData


@receiver(post_save, sender=DevicesData)
def post_save_handler(instance, **kwargs):
    print("signal!!!!")
    data = instance.init_data
    channel_layer = get_channel_layer()
    async_to_sync(channel_layer.group_send)(str(instance.owner.pk), {
        'type': 'send.data',
        'data': str(data)
    })
