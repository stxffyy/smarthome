from django.shortcuts import render, redirect
from django.views import View

from django_request_mapping import request_mapping


@request_mapping("/info")
class InfoView(View):
    @request_mapping("/")
    def get_info(self, request):
        if not request.user.is_authenticated:
            return redirect(f'/{request.LANGUAGE_CODE}/sign_in')

        return render(
            request,
            'control/info.html',
            context={},
        )
