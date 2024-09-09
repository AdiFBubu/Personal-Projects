from django import forms
from django.forms import TextInput, Select, ModelChoiceField

from aplicatie1.models import Location
from aplicatie2.models import Companies

company_choices = (     (None, 'Select a company type'),
                        ('SRL', 'S.R.L.'),
                       ('SA', 'S.A.'))
class CompanyForm(forms.ModelForm):

    class Meta:

        model = Companies
        fields = ['name', 'website', 'company_type', 'location']

        widgets = {
            'name': TextInput(attrs={'placeholder': 'Name value', 'class': 'form-control'}),
            'website': TextInput(attrs={'placeholder': 'Website value', 'class': 'form-control'}),
            #'company_type': Select(attrs={'class': 'form-control'}),
            #'location': Select(attrs={'class': 'form-control'}),
        }

    location = forms.ModelChoiceField(
        queryset=Location.objects.all(),
        widget=forms.Select(attrs={'class': 'form-control'}),
        help_text="Choose the location for the company",
        label="Location",  # Schimbarea etichetei câmpului
        empty_label="Select a location"  # Modificarea textului implicit pentru opțiunea de selecție
    )
    company_type = forms.TypedChoiceField(
        choices=company_choices,
        widget=forms.Select(attrs={'class': 'form-control'}),
    )

    def __init__(self, pk, *args, **kwargs):
        super(CompanyForm, self).__init__(*args, **kwargs)
        self.pk = pk

    def clean(self):
        name_value = self.cleaned_data.get('name')
        website_value = self.cleaned_data.get('website')

        if self.pk:
            if Companies.objects.filter(name__exact=name_value, website__exact=website_value).exclude(id=self.pk).exists():
                self._errors['website'] = self.error_class(['Numele si website-ul deja sunt inregistrate!'])
        else:
            if Companies.objects.filter(name__exact=name_value, website__exact=website_value).exists():
                self._errors['website'] = self.error_class(['Numele si website-ul deja sunt inregistrate!'])
        return self.cleaned_data