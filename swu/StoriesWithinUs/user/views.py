from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login, logout, update_session_auth_hash
from django.contrib import messages
from .forms import RegisterUserForm, EditUserForm, PasswordChangeUser, ForgotPasswordUser, ProfilePicture
from django.contrib.auth.models import User
from .models import Profile
from story.models import Story, Chapter

# profile
def edit_user(request):
    if request.user.is_authenticated:
        current_user = User.objects.get(id=request.user.id)
        profile_user = Profile.objects.get(user__id=request.user.id)
        form = EditUserForm(request.POST or None, request.FILES or None, instance=current_user)
        img_form = ProfilePicture(request.POST or None, request.FILES or None, instance=profile_user)

        if form.is_valid() and img_form.is_valid():
            form.save()
            img_form.save()
            messages.success(request, ("Your Information Has Been Updated"))
            return redirect('edit-user')
    else:
        messages.success(request, ('Cannot access this page as guest'))
        redirect('home')

    return render(request, 'edit_user.html', {'form':form, 'img_form':img_form})

def profile(request, pk):
    stories = Story.objects.filter(author_id=pk).values()
    total_stories = Story.objects.filter(author_id=pk).count()

    profile = Profile.objects.get(user_id=pk)

    if request.method == "POST":
        current_user_profile = request.user.profile
        action = request.POST['follow']
        if action == "unfollow":
            current_user_profile.follows.remove(profile)
        else:
            current_user_profile.follows.add(profile)
        current_user_profile.save()
    return render(request, 'profile.html', {'profile':profile, 'stories':stories, 'total_stories':total_stories})


# authentication
def try_again_forget(request):
    return render(request, 'authenticate/resend_link_password.html')

def forget_password(request):
    if request.method == "POST":
        form = RegisterUserForm(request.POST)
        if form.is_valid():
            form.save(from_email='phucnguyen.jvb@gmail.com')
            redirect('resend-link-password')
        else:
            messages.success(request, ('Something went wrong. Try again'))
            form=ForgotPasswordUser()

    return render(request, 'authenticate/forget_password.html', {'form':form})

        

def change_password(request):
    form = PasswordChangeUser(user=request.user, data=request.POST or None)
    if form.is_valid():
        form.save()
        update_session_auth_hash(request, form.user)
        messages.success(request, ("Password changed successfully!"))
        return redirect('edit-profile')
    return render(request, 'authenticate/change_password.html', {'form':form})

def logout_user(request):
    logout(request)
    messages.success(request, ("You Were Logged Out"))
    return redirect('home')

def login_user(request):
    if request.method == "POST":
        username = request.POST["username"]
        password = request.POST["password"]
        user = authenticate(request, username=username, password=password)
        if user is not None:
            login(request, user)
            return redirect('home')
        else:
            messages.success(request, ("Login failed. Please check your Username/Password"))
            return redirect('login')
    else:
        return render(request, 'authenticate/login.html', {})
    
    
def register_user(request):
    if request.method == "POST":
        form = RegisterUserForm(request.POST)
        if form.is_valid():
            form.save()
            username = form.cleaned_data['username']
            password = form.cleaned_data['password1']
            user = authenticate(username=username, password=password)
            login(request, user)
            messages.success(request, ("Registration Successful"))
            return redirect('home')
    else:
        form = RegisterUserForm()

    return render(request, 'authenticate/register.html', {'form': form})

