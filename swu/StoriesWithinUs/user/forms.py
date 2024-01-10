from django.contrib.auth.forms import UserCreationForm, UserChangeForm, PasswordChangeForm, PasswordResetForm
from django.contrib.auth.models import User
from django import forms
from .models import Profile

class ProfilePicture(forms.ModelForm):
    profile_image = forms.ImageField(label="Profile Picture")

    class Meta:
        model = Profile
        fields = ('profile_image', )

class RegisterUserForm(UserCreationForm):
    email = forms.EmailField(widget=forms.EmailInput(attrs={'class':'form-control'}))
    first_name = forms.CharField(max_length=50, widget=forms.TextInput(attrs={'class':'form-control'}))
    last_name = forms.CharField(max_length=50, widget=forms.TextInput(attrs={'class':'form-control'}))

    class Meta:
        model = User
        fields = ('username', 'first_name', 'last_name', 'email', 'password1', 'password2')

    def __init__(self, *args, **kwargs):
        super(RegisterUserForm, self).__init__(*args, **kwargs)
        
        self.fields['username'].widget.attrs['class'] = 'form-control'
        self.fields['password1'].widget.attrs['class'] = 'form-control'
        self.fields['password2'].widget.attrs['class'] = 'form-control'

class EditUserForm(UserChangeForm):
    username = forms.CharField(max_length=50, widget=forms.TextInput(attrs={'class':'form-control'}))
    email = forms.EmailField(widget=forms.EmailInput(attrs={'class':'form-control'}), required=False)
    first_name = forms.CharField(max_length=50, widget=forms.TextInput(attrs={'class':'form-control'}))
    last_name = forms.CharField(max_length=50, widget=forms.TextInput(attrs={'class':'form-control'}))
    password = None

    class Meta:
        model = User
        fields = ('username', 'first_name', 'last_name', 'email')

class PasswordChangeUser(PasswordChangeForm):
    class Meta:
        model = User

class ForgotPasswordUser(PasswordResetForm):
    email = forms.EmailField(widget=forms.EmailInput(attrs={'class':'form-control'}),required=True)

    class Meta:
        model = User
        fields = ("email")