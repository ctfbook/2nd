import requests
import json

headers = { 'Content-Type': 'application/json' }
data = json.dumps({ 'ctf': 'book' })

response = requests.post('http://localhost:5000', data=data)

if response.status_code == 200:
  print('[200 OK]', response.text)
else:
  print('[ERROR]', response.status_code)