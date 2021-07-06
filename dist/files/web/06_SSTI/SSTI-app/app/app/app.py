#! python3

from flask import (
    jsonify,
    Flask,
    request,
    redirect,
    render_template,
    render_template_string
)

import json
import pymysql

app = Flask(__name__)

app.config["MYSQL_DATABASE_HOST"] = "db"
app.config["MYSQL_DATABASE_DB"] = "db"
app.config["MYSQL_DATABASE_USER"] = "user"
app.config["MYSQL_DATABASE_PASSWORD"] = "password"

_db = pymysql.connect(
    host="db",
    db="db",
    user="user",
    password="password"
)


def get_db():
    _db.ping(reconnect=True)
    return _db
        

@app.route("/")
def route_index():
    sql = "select id, name from templates"

    db = get_db()
    cur = db.cursor()
    cur.execute(sql)

    data = cur.fetchall()

    return render_template("index.html", data=data)


@app.route("/view/<tid>")
def route_view(tid: int):
    
    sql = "select template from templates where id=%s limit 1"
    db = get_db()

    cur = db.cursor()
    cur.execute(sql, (tid,))
    data = cur.fetchone()
    if data == None:
        return "no template was found"

    template = data[0]
    return render_template_string(template)
    

@app.route("/add", methods=["GET"])
def route_add_index():
    
    return render_template("add.html")


@app.route("/add", methods=["POST"])
def route_add_do():

    sql_check = "select * from templates where name = %s"
    sql_insert = "insert into templates(name, template) values(%s, %s)"
    db = get_db()

    name = request.form.get("name")
    template = request.form.get("template")

    if name == "" or name == None or template == "" or template == None:
        return "name and template can not be empty."

    cur = db.cursor()
    cur.execute(sql_check, (name,))

    data = cur.fetchone()
    if data != None:
        return "name is duplicated."
    
    cur.execute(sql_insert, (name, template))
    db.commit()

    return redirect('/')


app.run(host="0.0.0.0", debug=False)


