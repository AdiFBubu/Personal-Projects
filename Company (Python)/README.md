&emsp;Perform the actions of: <br>
* listing company data
* add new company
* edit company data
* activate company data
* deactivate company data <br><br>
for the model: <br><br>
class Companies(models.Model): <br>
&emsp;&emsp;company_choices = (('SRL', 'S.R.L.'), ('SA', 'S.A.')) <br>
&emsp;&emsp;name = models.CharField(max_length=100) <br>
&emsp;&emsp;website = models.CharField(max_length=50) <br>
&emsp;&emsp;company_type = models.CharField(max_length=5, choices=company_choices) <br>
&emsp;&emsp;location = models.ForeignKey(Location, on_delete=models.CASCADE) <br><br>
&emsp;&emsp;def \_\_str\_\_(self): <br>
&emsp;&emsp;&emsp;return f"{self.company_type} {self.name}"
