# Generated by Django 4.2.3 on 2023-08-09 07:27

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('story', '0010_alter_chapter_name_alter_story_created_at_and_more'),
    ]

    operations = [
        migrations.AddField(
            model_name='tag',
            name='description',
            field=models.TextField(default='describe tag'),
        ),
    ]
