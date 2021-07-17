from flask import Flask, request, render_template, jsonify

app = Flask(__name__)

METHODS = ['GET', 'HEAD', 'POST', 'PUT', 'DELETE', 'CONNECT', 'OPTIONS', 'TRACE']

@app.route('/', defaults={'path': ''}, methods=METHODS)
@app.route('/<path:path>', methods=METHODS)
def index(path):
  '''
  リクエストのRequest-URI、メソッド及びヘッダーの内容をレスポンスする。
  '''

  return f'''
  <h1>Path: /{path}</h1>
  <h2>Method: {request.method}</h2>
  <h2>Request headers</h2>
  <ul>
    {''.join((f'<li>{name}: {value}</li>' for name, value in request.headers))}
  </ul>
  <h2>Request body</h2>
  <p>{ request.get_data().decode() if request.get_data() else 'None.' }</p>
  '''


if __name__ == '__main__':
  app.run(host='0.0.0.0', port=5000)
