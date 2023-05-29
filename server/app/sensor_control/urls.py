from django_request_mapping import UrlPattern

from .view.control import ControlView
from .view.device import DeviceView
from .view.info import InfoView
from .view.homepage import HomeView
urlpatterns = UrlPattern()
urlpatterns.register(ControlView)
urlpatterns.register(DeviceView)
urlpatterns.register(InfoView)
urlpatterns.register(HomeView)
