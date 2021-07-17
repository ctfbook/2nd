import requests

response = requests.get('http://localhost:5000')

if response.status_code == 200:
  print('[200 OK]', response.text)
else:
  print('[ERROR]', response.status_code)