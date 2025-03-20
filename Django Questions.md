# **1. Blog Post URL Pattern**

> You are building a blog website where each blog post should be accessible via a unique URL like `/post/5/`, where `5` is the post ID. How would you define the URL pattern and the corresponding view?
## Answer
### `urls.py`
Add these changes to `urls.py` of the main project
```python
from q1.views import q1_view
urlpatterns = [
path('q1/post/<int:post_id>', q1_view),
]
```
### `views.py`
In the app file make changes to the `views.py`
```python
from django.http import HttpResponse
def q1_view(request, post_id):
```
Something better would be to render a webpage
```python
from django.shortcuts import render
def q1_view(request, post_id):
    context = {'post_id': post_id}
    return render(request, "q1.html", context)
```
### `q1.html`
Defining a context is necessary to pass on the `post_id` as `context`
The template 'q1.html' is to be made to render in the view
```html
{% extends 'base.html' %}
    {% block content %}
        This is post id:
        <h1>{{post_id}}</h1>
    {% endblock %}
```
### `base.html`
Here the `base.html` looks like
```html
<!DOCTYPE html>
<html>
  <head>
    <title>{% block title %}My Project{% endblock %}</title>
    <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css"
      rel="stylesheet"/>
  </head>
  <body>
    <div id="content" class="container">{% block content %}{% endblock %}</div>
  </body>
</html>
```
### **2. Book Review Website**

> You are developing a book review website where users can visit a book’s detail page using a dynamic URL like `/book/harry-potter/`.
> 
> - You need to create a view and URL pattern to display the book title dynamically.
> - Create a URL pattern that captures the book name.
> - Write a view function that takes the book name from the URL and displays it on the page.

[base.html](###base.html)
### **3. Student Portal**

> You are building a student portal where each student has a profile page accessible via `/student/102/`, where `102` is the student ID.
> 
> - Create a URL pattern that captures the student ID.
> - Write a view function that extracts the ID and displays a custom message.

### **4. Template Inheritance**

> You want to introduce an intermediate template (`content_base.html`) between `base.html` and `about.html`. The structure should be:
> 
> - `base.html` (contains overall structure)
> - `content_base.html` (adds a `{% block page_title %}` inside an `<h2>` tag and `{% block page_content %}` for the main content)
> - `about.html` (extends `content_base.html`, overrides `{% block page_title %}` with `"About Us"`, and `{% block page_content %}` with `"This is the About Us page."`)

### **5. Food Ordering Website**

> Design a food ordering website using Django where users can:
> 
> - Browse available menu items
> - Add items to their shopping cart
> - Review and update their cart before placing an order
> - Place an order and receive an order confirmation
> - Track their order status as it moves from **"Pending" → "Preparing" → "On the Way" → "Delivered"**

### **6. User Profile Update Form**

> Create a **User Profile Update Form** in Django that allows users to update their profile details and upload a profile picture.  
> **Form Fields:**
> 
> - `username` (CharField, max length 150, required)
> - `email` (EmailField, required)
> - `bio` (TextArea, optional)
> - `profile_picture` (ImageField, optional)  
>     **Validation Rules:**
> - Username must be at least 4 characters long.
> - Email should be in a valid format.
> - Profile picture must be a JPG, PNG, or GIF file.  
>     **Tasks:**
> - Render the form on a webpage
> - Validate input upon submission
> - Save the updated profile details in the database
> - Show a success message if the update is successful
> - Display the form using `POST` and `enctype="multipart/form-data"` for file upload
> - Show validation error messages
> - Use Bootstrap styling for a clean layout

### **7. User Registration Form**

> Create a **User Registration Form** in Django with the following requirements:  
> **Form Fields:**
> 
> - `username` (CharField, max length 150)
> - `email` (EmailField)
> - `password` (PasswordInput)
> - `confirm_password` (PasswordInput)  
>     **Validation Rules:**
> - `username` must be at least 4 characters long.
> - `email` should be a valid email format.
> - `password` must be at least 6 characters long.
> - `confirm_password` must match `password`.  
>     **Tasks:**
> - Render the form on a webpage.
> - Validate input upon submission.
> - Show a success message if the form is valid.
> - Display errors if validation fails.

### **8. Simple Django Form**

> Create a **Django form class** named `SimpleForm` with two fields:
> 
> - `name` (CharField, max length 100)
> - `email` (EmailField)  
>     Write the corresponding Django **view** and **template** code to display this form.

### **9. Medical Appointment Form**

> Create a **Medical Form** in Django with the following requirements:  
> **Form Fields:**
> 
> - `patient_name` (CharField, max length 150)
> - `age` (IntegerField, must be between 0-120)
> - `email` (EmailField)
> - `phone` (CharField, max length 15, must contain only digits)
> - `gender` (ChoiceField with options: Male, Female, Other)
> - `symptoms` (Textarea for patient symptoms)
> - `appointment_date` (DateField with a date picker)  
>     **Validation Rules:**
> - `patient_name`: Required and cannot be empty.
> - `age`: Must be a valid integer between 0 and 120.
> - `email`: Should be a valid email format.
> - `phone`: Should contain only numbers and be at least 10 digits long.
> - `symptoms`: Required and must not be empty.
> - `appointment_date`: Must be a valid date.  
>     **Tasks:**
> - Render the form on a webpage.
> - Validate input upon submission.
> - Show a success message if the form is valid.
> - Display error messages for invalid input.

### **10. Blood Donation Management System**

> **Scenario:** Design a simple web application to manage a blood donation campaign.  
> **Tasks:**
> 
> 1. Create a view `donor_list` to display a list of registered blood donors with fields:
>     - `name`, `blood_group`, `city`, and `contact_number`.
> 2. Set up a URL `/donors/` to map to this view.
> 3. Design a `donor_list.html` template to display the donor details in a table.
> 4. Add a heading and a footer section with contact information for the blood donation center.

### **11. Local Event Website**

> **Scenario:** Build a web application to display and manage community events.  
> **Tasks:**
> 
> 1. Create a view `event_list` that fetches all upcoming events from the database with fields:
>     - `title`, `description`, `date`, `time`, and `location`.
> 2. Set up a URL `/events/` to display the list of events.
> 3. Create an `event_list.html` template that shows the event details in a card format.

### **12. Job Portal for Rural Areas**

> **Scenario:** Develop a job portal to connect employers and job seekers in rural areas.  
> **Tasks:**
> 
> 1. Create a view `job_list` that retrieves all available job postings with fields:
>     - `title`, `description`, `company_name`, `location`, and `salary`.
> 2. Set up a URL `/jobs/` to map to the job listing page.
> 3. Design a `job_list.html` template to display job postings.
> 4. Include a button to view the details of each job (linked to a `job_detail` view).

### **13. Public Grievance System**

> **Scenario:** Create a web application for citizens to submit and track grievances.  
> **Tasks:**
> 
> 1. Create a view `grievance_list` that displays all submitted grievances with fields:
>     - `complaint_title`, `category`, `status`, and `date_submitted`.
> 2. Create another view `grievance_detail` to display the details of a specific grievance.
> 3. Set up URLs:
>     - `/grievances/` for the grievance list.
>     - `/grievances/<int:id>/` for viewing grievance details.
> 4. Create templates `grievance_list.html` and `grievance_detail.html`.
> 5. Include navigation buttons to go back to the list page.

### **14. Volunteer Registration Portal**

> **Scenario:** Develop a website for a non-profit organization to register and manage volunteers.  
> **Tasks:**
> 
> 1. Create a view `volunteer_list` to display all registered volunteers with fields:
>     - `name`, `email`, `city`, `skills`, and `availability`.
> 2. Set up a URL `/volunteers/` for the volunteer list.
> 3. Create a `volunteer_list.html` template that displays the volunteer details in a responsive table.
> 4. Add a form to filter volunteers by skill (bonus functionality).