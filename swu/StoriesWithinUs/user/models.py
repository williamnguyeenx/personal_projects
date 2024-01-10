from django.db import models
from django.contrib.auth.models import User
from django.db.models.signals import post_save
from story.models import Story

# Create your models here.

class Profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    bio = models.TextField(blank=True)
    follows = models.ManyToManyField("self", related_name="followed_by", symmetrical=False, blank=True)
    profile_image = models.ImageField(null=True, blank=True, upload_to="img/")

    def __str__(self):
        return self.user.username
    
def create_profile(sender, instance, created, **kwargs):
    if created:
        user_profile = Profile(user=instance)
        user_profile.save()

post_save.connect(create_profile, sender=User)