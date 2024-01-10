from django.db import models
from ckeditor.fields import RichTextField
from django.contrib.auth.models import User

class Tag(models.Model):
    name = models.CharField()

    def __str__(self):
        return self.name

class Story(models.Model):
    name = models.CharField()
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)
    author = models.ForeignKey(User, blank = True, null = True, on_delete=models.CASCADE)
    description = models.TextField(blank=True)
    tag = models.ForeignKey(Tag, blank = True, null = True, on_delete=models.CASCADE)
    likes = models.ManyToManyField(User, related_name='swu_story', blank=True)
    story_image = models.ImageField(null=True, blank=True, upload_to="img/")

    def __str__(self):
        return self.name
    
    def total_likes(self):
        return self.likes.count()

class Chapter(models.Model):
    story = models.ForeignKey(Story, blank = True, null = True, on_delete=models.CASCADE)
    name = models.CharField()
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)    
    description = RichTextField(blank = True, null = True)
    

    def __str__(self):
        return self.name
    
class Comment(models.Model):
    story = models.ForeignKey(Story, related_name="comments", blank = True, null = True, on_delete=models.CASCADE)
    name = models.ForeignKey(User, related_name="comment_user", blank = True, null = True, on_delete=models.CASCADE)
    body = models.TextField()
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return '%s - %s' % (self.story.name, self.name)
