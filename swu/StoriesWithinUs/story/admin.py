from django.contrib import admin
from .models import Story, Chapter, Tag, Comment

admin.site.register(Story)
admin.site.register(Chapter)
admin.site.register(Tag)
admin.site.register(Comment)