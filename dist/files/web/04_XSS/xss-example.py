from flask import Flask, request

app = Flask(__name__)

@app.route('/')
def index():
  name = request.args.get('name', 'unknown')
  return f'<p>Hello, {name}!</p>'

app.run(host='0.0.0.0', port=5000)