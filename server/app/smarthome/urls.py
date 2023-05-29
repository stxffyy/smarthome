from django.contrib import admin
from django.urls import path, include
from django.conf.urls.i18n import i18n_patterns

import accounts.urls
import sensor_control.urls

urlpatterns = [
    path('admin/', admin.site.urls),
]

urlpatterns += i18n_patterns(
    path('i18n/', include('django.conf.urls.i18n')),
    path('', include(accounts.urls)),
    path('', include(sensor_control.urls)),
)
