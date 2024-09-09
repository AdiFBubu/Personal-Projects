from django.urls import path

from pontaj import views

app_name = "pontaj"

urlpatterns = [
    path('start_timesheet/', views.new_timesheet, name='start_pontaj'),
    path('end_timesheet/', views.stop_timesheet, name='end_pontaj'),
]