from flask import Flask, request, Response
import base64
import random

app = Flask(__name__)

def get_nonce():
  return f'{base64.b64encode(str(random.random()).encode()).decode()}'

@app.route('/')
def index():
  name = request.args.get('name', 'unknown')
  title = request.args.get('title', 'unknown')

  nonce = get_nonce()

  res = Response(f'''
  <script nonce="{nonce}">
    window.onload = () => {{
      const name = (new URL(location).searchParams).get('name')
      document.getElementById("greeting").innerHTML = `${{name ?? 'unknown'}}!`
    }}
  </script>
  <h1>{title}</h1>
  <p id="greeting">Hello, </p>
  ''')
  
  res.headers['Content-Security-Policy'] = f'default-src \'none\'; script-src \'strict-dynamic\' \'nonce-{nonce}\''

  return res

app.run(host='0.0.0.0', port=5000)