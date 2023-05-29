from django.shortcuts import render, redirect
from django.views import View

from django_request_mapping import request_mapping


@request_mapping("/")
class HomeView(View):
    @request_mapping("/")
    def get_info(self, request):
        if request.user.is_authenticated:
            return redirect(f'/{request.LANGUAGE_CODE}/control/')

        return redirect(f'/{request.LANGUAGE_CODE}/sign_in/')