from django import forms
from django.forms import ModelForm
from .models import Story, Chapter, Tag, Comment
from django.contrib.auth.models import User
from ckeditor.widgets import CKEditorWidget

class StoryImage(ModelForm):
    story_image = forms.ImageField(label="Story Cover")

    class Meta:
        model = Story
        fields = ('story_image', )

class StoryInfo(ModelForm):
    name = forms.CharField(widget=forms.TextInput(attrs={'class':'form-control'}))
    author = forms.ModelChoiceField(queryset=User.objects.all(), widget=forms.HiddenInput(attrs={'class':'form-control', 'value':'username', 'id':"author"}))
    description = forms.CharField(widget=forms.TextInput(attrs={'class':'form-control'}))
    tag = forms.ModelChoiceField(queryset=Tag.objects.all(), widget=forms.Select(attrs={'class':'form-control'}))

    class Meta:
        model = Story
        fields = ('name', 'author','description', 'tag', 'story_image')


class ChapterInfo(ModelForm):
    story = forms.ModelChoiceField(queryset=Story.objects.all(), widget=forms.HiddenInput(attrs={'class':'form-control', 'value':'name', 'id':"story"}))
    name = forms.CharField(widget=forms.TextInput(attrs={'class':'form-control'}))
    description = forms.CharField(widget=CKEditorWidget())

    class Meta:
        model = Chapter
        fields = ('story','name', 'description')

class TagInfo(ModelForm):
    class Meta:
        model = Tag
        fields = ('name',)

class CommentInfo(ModelForm):
    story = forms.ModelChoiceField(queryset=Story.objects.all(), widget=forms.HiddenInput(attrs={'class':'form-control', 'value':'name', 'id':"story"}))
    name = forms.ModelChoiceField(queryset=User.objects.all(), widget=forms.HiddenInput(attrs={'class':'form-control', 'value':'name', 'id':"author"}))
    body = forms.CharField(widget=forms.Textarea(attrs={'class':'form-control', 'placeholder':'Add a comment', 'name':'Add a comment'}))

    class Meta:
        model = Comment
        fields = ('story', 'name', 'body')

    def __init__(self, *args, **kwargs):
        super(CommentInfo, self).__init__(*args, **kwargs)
        self.fields['body'].label = ""
