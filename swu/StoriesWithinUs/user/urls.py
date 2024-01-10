"""
URL configuration for StoriesWithinUs project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.urls import path
from . import views

urlpatterns = [
    path('login_user', views.login_user, name='login'),
    path('logout_user', views.logout_user, name='logout'),
    path('register_user', views.register_user, name='register_user'),
    path('edit_user', views.edit_user, name='edit-user'),
    path('profile/<int:pk>', views.profile, name='profile'),
    path('change_password', views.change_password, name='change-password'),
    path('forget_password', views.forget_password, name='forget-password'),
    path('resend_link_password', views.try_again_forget, name='resend-link-password'),
]
