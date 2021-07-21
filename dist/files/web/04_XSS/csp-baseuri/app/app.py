from flask import Flask, request, Response
import base64
import random

app = Flask(__name__)

def get_nonce():
  return f'{base64.b64encode(str(random.random()).encode()).decode()}'

@app.route('/')
def index():
  name = request.args.get('name', 'unknown')

  nonce = get_nonce()

  res = Response(f'''
  <script src="/static/index.js" nonce="{nonce}"></script>
  <p id="greeting">Hello, {name}!</p>
  ''')
  
  res.headers['Content-Security-Policy'] = f'script-src \'nonce-{nonce}\''

  return res

app.run(host='0.0.0.0', port=5000)