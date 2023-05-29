from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from .forms import UserLoginForm, UserRegistrationForm


def login_account(request):
    if request.method == 'POST':
        form = UserLoginForm(request.POST)
        if form.is_valid():
            cd = form.cleaned_data
            user = authenticate(username=cd['username'], password=cd['password'])
            if user is not None:
                if user.is_active:
                    login(request, user)
                    return redirect('/control/')
                else:
                    return redirect('sign_up')
            else:
                return redirect('sign_in')
    else:
        form = UserLoginForm()
    return render(request, 'accounts/sign_in.html', {'form': form})


@login_required(login_url='/sign_in/')
def logout_user(request):
    logout(request)


def register_account(request):
    form = UserRegistrationForm()

    if request.method == 'POST':
        form = UserRegistrationForm(request.POST)
        if form.is_valid():
            new_user = form.save(commit=False)
            new_user.set_password(form.cleaned_data['password1'])
            new_user.save()

            return redirect('sign_in')
    return render(request, 'accounts/sign_up.html', {'form': form})


def password_recovery(request):
    return render(request, 'accounts/password_recovery.html')
