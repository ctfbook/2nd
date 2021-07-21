import requests

session = requests.Session()

url = '...'
login_data = {
  'id': '...',
  'password': '...'
}

# このPOSTリクエストに対するレスポンスに以下のヘッダーが存在した場合
# Set-Cookie: SESSION=123456...
login_response = session.post(url + '/login', data=login_data)

# このGETリクエストのヘッダーに以下のCookieヘッダーが自動で付与される
# Cookie: SESSION=123456...
data_response = session.get(url + '/data')