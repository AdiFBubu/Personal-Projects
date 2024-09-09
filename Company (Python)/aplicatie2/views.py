from django.contrib.auth.decorators import login_required
from django.contrib.auth.mixins import LoginRequiredMixin
from django.shortcuts import render, redirect
from django.urls import reverse
from django.views.generic import ListView, CreateView, UpdateView

from aplicatie2.forms import CompanyForm
from aplicatie2.models import Companies


# Create your views here.
class CompanyView(LoginRequiredMixin, ListView):
    model = Companies
    template_name = 'aplicatie2/company_index.html'

class CreateCompanyView(LoginRequiredMixin, CreateView):
    model = Companies
    form_class = CompanyForm
    template_name = 'aplicatie1/location_form.html'

    def get_form_kwargs(self):
        data = super(CreateCompanyView, self).get_form_kwargs()
        data.update({'pk': None})
        return data

    def get_success_url(self):
        return reverse('aplicatie2:lista_companii')
class UpdateCompanyView(LoginRequiredMixin, UpdateView):
    model = Companies
    form_class = CompanyForm
    template_name = 'aplicatie1/location_form.html'

    def get_form_kwargs(self):
        data = super(UpdateCompanyView, self).get_form_kwargs()
        data.update({'pk': self.kwargs['pk']})
        return data

    def get_success_url(self):
        return reverse('aplicatie2:lista_companii')

@login_required
def deactivate_company(request, pk):
    Companies.objects.filter(id=pk).update(active = 0)
    return redirect('aplicatie2:lista_companii')

@login_required
def activate_company(request, pk):
    Companies.objects.filter(id=pk).update(active=1)
    return redirect('aplicatie2:lista_companii')
