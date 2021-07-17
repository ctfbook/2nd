from flask import Flask, request

app = Flask(__name__)

@app.route('/simple')
def simple():
  name = request.args.get('name', 'unknown')
  return f'<p>Hello, {name}!</p>'

@app.route('/attribute_without_quote')
def attribute_without_quote():
  name = request.args.get('name', 'unknown')
  return f'Name: <input type=text value={name}>'

@app.route('/attribute_with_quote')
def attribute_with_quote():
  name = request.args.get('name', 'unknown')
  return f'Name: <input type=text value="{name}">'

@app.route('/dom_based')
def dom_based():
  return '''
    <p id="greeting"></p>

    <script>
    const name = decodeURIComponent(location.search.substr(1))
    document.getElementById('greeting').innerHTML = `Hello, ${name || 'unknown'}`
    </script>
  '''

app.run(host='0.0.0.0', port=5000)