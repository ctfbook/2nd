import requests

headers = {'MY_HEADER': 'CTF_IS_FUN'}
params = {'my_query': '123'}
cookies = {'MY_COOKIE': 'abc'}

response = requests.get('http://localhost:5000',
  headers=headers, params=params, cookies=cookies)

if response.status_code == 200:
  print('[200 OK]', response.text)
else:
  print('[ERROR]', response.status_code)