#! python3

from flask import (
    Flask,
    request,
    redirect,
    render_template,
    session
)

from lxml import etree

app = Flask(__name__)
FLAG = None


def auth(username, password):
    return False


@app.route("/", methods=["GET"])
def route_index():
    return render_template("index.html")


@app.route("/login", methods=["POST"])
def route_login_do():
    xml = request.get_data().decode()

    parser = etree.XMLParser(no_network=False, remove_blank_text=True)

    try:
        doc = etree.fromstring(xml, parser=parser)
    except:
        return "Invalid Request", 400, {"Content-Type": "text/plain"}

    try:
        username = doc.find("username").text
        password = doc.find("password").text
    except:
        return "username and password are required", 400, {"Content-Type": "text/plain"}
        
    if auth(username, password) == True:
        session['logined'] = True
        return redirect('/flag')

    resp = etree.Element("result")
    resp_success = etree.Element("success")
    resp_success.text = "false"

    resp.append(resp_success)

    return etree.tostring(resp, pretty_print=True), 200, {"Content-Type": "application/xml"}


@app.route("/flag", methods=["GET"])
def route_flag():
    if "logined" in session and session["logined"] == True:
        return FLAG

    return "Please login :D", 403

    
def init():
    global FLAG

    parser = etree.XMLParser(no_network=False)
    doc = etree.parse('/opt/app/config.xml', parser=parser)
    FLAG = doc.find("flag").text


init()
app.run(host="0.0.0.0", debug=False)
