Perform the actions of: <br>
* listing company data
* add new company
* edit company data
* activate company data
* deactivate company data
for the model: <br><br>
class Companies(models.Model):
    company_choices = (('SRL', 'S.R.L.'),
                       ('SA', 'S.A.'))

    name = models.CharField(max_length=100) <br>
    website = models.CharField(max_length=50) <br>
    company_type = models.CharField(max_length=5, choices=company_choices) <br>
    location = models.ForeignKey(Location, on_delete=models.CASCADE) <br>

    def __str__(self): <br>
        return f"{self.company_type} {self.name}"
