from django.urls import path
from . import views

urlpatterns = [
    path('', views.home, name='home'),

    path('list_stories', views.list_stories, name='list-stories'),
    # path('list_fav_stories', views.list_fav_stories, name='list-fav-stories'),
    path('list_tags', views.list_tags, name='list-tags'),
    path('search', views.search, name='search'),

    path('show_story/<story_id>', views.show_story, name='show-story'),
    path('show_chapter/<chapter_id>', views.show_chapter, name='show-chapter'),
    path('show_tag/<tag_id>', views.show_tag, name='show-tag'),

    path('add_story', views.add_story, name='add-story'),
    path('add_chapter/<story_id>', views.add_chapter, name='add-chapter'),
    path('article/<story_id>/comment', views.add_comment, name='add-comment'),
    
    path('update_tag/<tag_id>', views.update_tag, name='update-tag'),
    path('update_story/<story_id>', views.update_story, name='update-story'),
    path('update_chapter/<chapter_id>', views.update_chapter, name='update-chapter'),

    path('delete_tag/<tag_id>', views.delete_tag, name='delete-tag'),
    path('delete_chapter/<chapter_id>', views.delete_chapter, name='delete-chapter'),
    path('delete_story/<story_id>', views.delete_story, name='delete-story'),
    
    
    path('like/<story_id>', views.like_story, name='like-story')
]