from django.db import models

# Create your models here.
class Pontaj(models.Model):

    user = models.ForeignKey('auth.User', on_delete=models.CASCADE)
    start_date = models.DateTimeField()
    end_date = models.DateTimeField(null=True)

class Logs(models.Model):

    created_at = models.DateTimeField(auto_now_add=True)
    user = models.ForeignKey('auth.User', on_delete=models.CASCADE)
    action = models.CharField(max_length=50)
    url = models.CharField(max_length=50)