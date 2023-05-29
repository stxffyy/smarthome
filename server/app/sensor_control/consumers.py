from channels.generic.websocket import AsyncJsonWebsocketConsumer


class WSConsumer(AsyncJsonWebsocketConsumer):
    def __init__(self, *args, **kwargs):
        super().__init__(args, kwargs)
        self.user = None

    async def connect(self):
        self.user = str(self.scope['user'].pk)

        await self.channel_layer.group_add(
            self.user,
            self.channel_name
        )
        await self.accept()

    async def disconnect(self, code):
        await self.channel_layer.group_discard(
            self.user,
            self.channel_name
        )

    async def send_data(self, event):
        await self.send_json(content=event['data'])

    async def receive_json(self, content, **kwargs):
        await self.channel_layer.group_send(self.user, {
            'type': 'send.data',
            'data': content
        })
