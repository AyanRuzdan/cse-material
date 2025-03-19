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