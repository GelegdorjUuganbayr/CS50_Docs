# flask

### application.py
```python
""" pseudo code
if request is for /
  then send back index.html
else if request is for /zuck
  then send zuck.html
else if request is for /login
  then show user login.html
"""

from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
  return render_template("index.html")

@app.route("/zuck")
def zuck():
  return render_template("zuck.html")

@app.route("/login")
def login():
  return render_template("login.html")
```

### index.html
```html
<!DOCTYPE html>

<html>
  <head>
    <title>hello, title</title>
  </html>
  <body>
    hello, body
  </body>
</html>
```

### zuck.html
```html
<!DOCTYPE html>

<html>
  <head>
    <title>hello, title</title>
  </html>
  <body>
    I am Mark.
  </body>
</html>
```

---

## Interactive server
### application.py
```python
from flask import Flask, render_template, request

# Registration
students = []

app = Flask(__name__)

@app.route("/")
def index():
  return render_template("index.html")

@app.route("/registrants")
def registrants():
  return render_template("registrants.html", students=students)

@app.route("/register", methods=["POST"]) # when usr call /register
def register():
  name = request.form.get("name")
  dorm = request.form.get("dorm")
  if not request.form.get("name") or not request.form.get("dorm"):
    return render_template("failure.html")
  students.append(f"{name} from {dorm}")
  return redirect("/registrations")
```

### layout.html
```html
<!DOCTYPE html>

<html>
  <head>
    <title>{{ PUT SOMTHING HERE }}</title>
  </html>
  <body>
    {{ PUT SOMETHING ELSE HERE }}
  </body>
</html>
```

### failure.html
```html
{% extends "layout.html" %}

{% block body %}
You must provide your name and dorm!
{% endblock %}
```

### registrants.html
```html
{% extends "layout.html" %}

{% block body %}

<ul>
  {% for student in students %}
  <li>{{ student }}</li>
  {% endfor %}
</ul>

{% endblock %}
```
