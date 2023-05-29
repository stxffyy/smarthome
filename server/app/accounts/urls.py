from django.urls import path
from django.contrib.auth.views import LogoutView
from django.conf import settings
from .views import (
    register_account,
    login_account,
    password_recovery
)

urlpatterns = [
    path('sign_up/', register_account, name='sign_up'),
    path('sign_in/', login_account, name='sign_in'),
    path('password_recovery/', password_recovery, name='password_recovery'),
    path('sign_out/', LogoutView.as_view(), {'next_page': settings.LOGOUT_REDIRECT_URL}, name='sign_out'),
]
