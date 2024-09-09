from django.urls import path

from aplicatie2 import views

app_name = 'aplicatie2'

urlpatterns = [
    path('', views.CompanyView.as_view(), name='lista_companii'),
    path('adaugare/', views.CreateCompanyView.as_view(), name='adaugare'),
    path('<int:pk>/modificare/', views.UpdateCompanyView.as_view(), name='modificare'),
    path('<int:pk>/dezactiveaza/', views.deactivate_company, name='dezactivare'),
    path('<int:pk>/activeaza/', views.activate_company, name='activare'),
]