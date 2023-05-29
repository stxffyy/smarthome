from django.db import models
from django.utils import timezone
from django.contrib.auth.models import User


class DevicesData(models.Model):
    date_created = models.DateTimeField(default=timezone.now)
    owner = models.ForeignKey(User, on_delete=models.CASCADE)
    ip = models.TextField()
    init_data = models.JSONField()
    sensors_data = models.JSONField()
    executors_data = models.JSONField()

    def __str__(self):
        return str(self.init_data) + ' - ' + str(self.sensors_data) + ' - ' + str(self.executors_data)

