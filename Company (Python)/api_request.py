import requests

url = "https://v6.exchangerate-api.com/v6/b388c0d4a753f0e4951f5f75/latest/USD"

payload = {}
headers = {
  'Authorization': 'Token b388c0d4a753f0e4951f5f75'
}

response = requests.request("GET", url, headers=headers, data=payload)

print(response.json()["conversion_rates"]['EUR'])
