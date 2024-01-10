from django.shortcuts import render, redirect, get_object_or_404
from .models import Story, Chapter, Tag
from .forms import StoryInfo, ChapterInfo, TagInfo, CommentInfo, StoryImage
from django.http import HttpResponseRedirect
from django.core.paginator import Paginator
from django.urls import reverse
from django.contrib.auth.models import User
from django.contrib import messages


# like/unlike
def like_story(request, story_id):
    if request.user.is_authenticated:
        story = get_object_or_404(Story, id=story_id)
        if story.likes.filter(id=request.user.id):
            story.likes.remove(request.user)
        else:
            story.likes.add(request.user)
    else:
        messages.success(request,("You must be logged in to like story"))

    return redirect(request.META.get("HTTP_REFERER"))


# remove
def delete_tag(request, tag_id):
    tag = Tag.objects.get(pk=tag_id)
    tag.delete()
    return redirect('list-tags')

def delete_chapter(request, chapter_id):
    chapter = Chapter.objects.get(pk=chapter_id)
    chapter.delete()
    return redirect(request.META.get("HTTP_REFERER"))

def delete_story(request, story_id):
    story = Story.objects.get(pk=story_id)
    story.delete()
    return HttpResponseRedirect(reverse('profile', args=[str(request.user.id)]))


# edit
def update_tag(request, tag_id):
    tag = Tag.objects.get(pk=tag_id)
    form = TagInfo(request.POST or None, instance=tag)
    if form.is_valid():
        form.save()
        return redirect('home')
    context = {'tag':tag, 'form':form}

    return render(request, 'update_tag.html', context)

def update_chapter(request, chapter_id):
    chapter = Chapter.objects.get(pk=chapter_id)
    story_id = Chapter.objects.filter(id=chapter_id).values('story_id').get()['story_id']
    story = Story.objects.get(pk=story_id)

    form = ChapterInfo(request.POST or None, instance=chapter)
    if form.is_valid():
        form.save()
        return HttpResponseRedirect(reverse('show-chapter', args=[str(chapter_id)]))
    context = {'chapter':chapter, 'form':form, 'story':story}

    return render(request, 'update_chapter.html', context)

def update_story(request, story_id):
    story = Story.objects.get(pk=story_id)
    form = StoryInfo(request.POST or None, instance=story)
    if form.is_valid():
        form.save()
        return HttpResponseRedirect(reverse('show-story', args=[str(story_id)]))
    context = {'story':story, 'form':form}

    return render(request, 'update_story.html', context)


# add
def add_comment(request, story_id):
    submitted = False
    if request.method == "POST":
        form = CommentInfo(request.POST)
        if form.is_valid():
            form.save()
            return HttpResponseRedirect(reverse('show-story', args=[str(story_id)]))
    else:
        form = CommentInfo
        if 'submitted' in request.GET:
            submitted == True

def add_chapter(request, story_id):
    submitted = False
    if request.method == "POST":
        form = ChapterInfo(request.POST)
        if form.is_valid():
            form.save()
            messages.success(request, ('Submitted Successfully!'))
            return HttpResponseRedirect(reverse('add-chapter', args=[str(story_id)]))
    else:
        form = ChapterInfo
        if 'submitted' in request.GET:
            submitted == True

    story = Story.objects.get(pk=story_id)

    context = {'form':form, 'submitted': submitted, 'story':story}
    
    return render(request, 'add_chapter.html', context)

def add_story(request):
    submitted = False
    if request.method == "POST":
        form = StoryInfo(request.POST)
        if form.is_valid():
            form.save()
            return HttpResponseRedirect(reverse('profile', args=[str(request.user.id)]))
    else:
        form = StoryInfo
        if 'submitted' in request.GET:
            submitted == True
    return render(request, 'add_story.html', {'form':form, 'submitted': submitted })


# show
def show_tag(request, tag_id):
    tag = Tag.objects.get(pk=tag_id)
    stories = Story.objects.filter(tag_id=tag_id).all()
    context = {'tag':tag, 'stories':stories}

    return render(request, 'show_tag.html', context)

def show_chapter(request, chapter_id):
    chapter = Chapter.objects.get(pk=chapter_id)
    story_id = Chapter.objects.filter(id=chapter_id).values('story_id').get()['story_id']
    story = Story.objects.get(pk=story_id)
    chapters = Chapter.objects.filter(story_id=story_id).values()

    submitted = False
    if request.method == "POST":
        form = CommentInfo(request.POST)
        if form.is_valid():
            form.save()
            return HttpResponseRedirect(reverse('show-chapter', args=[str(chapter_id)]))
    else:
        form = CommentInfo
        if 'submitted' in request.GET:
            submitted == True

    context = {'story':story, 'chapter':chapter, 'chapters':chapters, 'form':form}

    return render(request, 'show_chapter.html', context)

def show_story(request, story_id):
    story = Story.objects.get(pk=story_id)
    chapters = Chapter.objects.filter(story_id=story_id).values()

    submitted = False
    if request.method == "POST":
        form = CommentInfo(request.POST)
        if form.is_valid():
            form.save()
            return HttpResponseRedirect(reverse('show-story', args=[str(story_id)]))
    else:
        form = CommentInfo
        if 'submitted' in request.GET:
            submitted == True
            
    context = {'story':story, 'chapters':chapters,'form': form}

    return render(request, 'show_story.html', context)

def search(request):
    if request.method == "POST":
        searched = request.POST['searched']
        stories = Story.objects.filter(name__icontains=searched).order_by('updated_at')
        return render(request,'search.html', {'searched':searched, 'stories':stories})
    
    else:
        p = Paginator(Story.objects.all(), 4)
        page = request.GET.get('page')
        story_list = p.get_page(page)
        return render(request,'search.html', {'story_list':story_list})

def list_tags(request):
    tag_list = Tag.objects.all().order_by('name')

    p = Paginator(Tag.objects.all(), 10)
    page = request.GET.get('page')
    tags = p.get_page(page)
    num = 'a'* tags.paginator.num_pages

    context={'tag_list': tag_list, 'tags':tags, 'num':num}

    return render(request, 'list_tags.html', context)

def list_stories(request):
    story_list = Story.objects.all().order_by('updated_at')

    p = Paginator(Story.objects.all(), 5)
    page = request.GET.get('page')
    stories = p.get_page(page)
    num = "a" * stories.paginator.num_pages

    context={'story_list': story_list, 'stories':stories, 'num':num}

    return render(request, 'list_stories.html', context)


# homepage
def home(request):
    story_list = Story.objects.all().order_by('updated_at')

    p = Paginator(Story.objects.all(), 5)
    page = request.GET.get('page')
    stories = p.get_page(page)
    num = "a" * stories.paginator.num_pages

    return render(request, 'home.html', {'story_list': story_list, 'stories':stories, 'num':num})