## Creating a virtual environment
```bash
python -m venv env
```
Makes a virtual environment of name `env`
## Accessing the virtual environment
```bash
.\env\Scripts\activate
```
## Install Django
```bash
pip install django
```
## Create new project
```bash
django-admin startproject project_name
```
## Run django project
```bash
python manage.py runserver
```
## `settings.py`
You need to include name of apps in the `INSTALLED_APPS` list so that django identifies which app to access.
Templates are also to be specified into `TEMPLATES`.
In order to relink the changes made in `settings.py` run `python manage.py migrate`.
> Wherever `manage.py` is the folder where the root of the project is.
## Create new app
```bash
python manage.py startapp app_name
```
> Apps can be removed by simply deleting their folders
## Returning something on the page
You have to make changes to the 'views.py' file,i.e. making functions that return stuff that you want to see on the browser.
Initially you can use `HttpResponse` to render html directly via the view function that returns html text. Then in order to actually view it and link it to the url, go to `urls.py` of the project and add the path to the `urlpatterns`, for example
```python
from django.contrib import admin
from django.urls import path
from pages import views
urlpatterns = [
    path("admin/", admin.site.urls),
    path("", views.home_view),
]
```
Don't forget to import the views
In order to specify any specific url to access a given function, `urlpatterns` can be changed accordingly. For example
```python
path("home/", views.home_view),
```
will now render the data from the `views.py` and not on localhost directly.
>Previously: `http://127.0.0.1:8000/`
>Now: `http://127.0.0.1:8000/home/`
>Previous `views.py`:
```python
from django.contrib import admin
from django.urls import path
from pages import views
urlpatterns = [
    path("admin/", admin.site.urls),
    path("", views.home_view),
]
```
>Current `views.py`:
```python
from django.contrib import admin
from django.urls import path
from pages import views
urlpatterns = [
    path("admin/", admin.site.urls),
    path("home/", views.home_view),
]
```
## Django Templates

