from django.urls import path
from .consumers import WSConsumer

ws_urlpatterns = [
    path('ws/get_data/', WSConsumer.as_asgi(), name='ws_get_data')
]
