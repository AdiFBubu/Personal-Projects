from django.shortcuts import render
from rest_framework import viewsets

from aplicatie1.models import Location
from my_api.serializers import LocationSerializer


# Create your views here.
class LocationViewSet(viewsets.ModelViewSet):
    queryset = Location.objects.all()
    serializer_class = LocationSerializer

