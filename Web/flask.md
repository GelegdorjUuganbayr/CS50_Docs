# flask
> flask.pocoo.org/docs/0.12/quickstart/\
> jinja.pocoo.org/
- python contains native functionality to support networking and more, enabling site backends to be written in python.
- Web frameworks make the process easier, abstracting away the minutia of Python's syntax and providing helper functions.
  - Django, Pyramid, Flask
- HTML suffer from a limitation - Static
- Incorporating python can make it flexible and dynamic without requiring human intervention.
- Decorators are used to associate a particular function with a particular URL

**html - current time**
```html
<html>
  <head>
    <title>Current Time in Cambridge</title>
  </html>
  <body>
    The current time in Cambridge is 14:08
  </body>
</html>
```

**Flask - current time**
```python
from flask import Flask
from datetime import datetime
from pytz import timezone

app = Flask(__name__) # initiate a Flask application

@app.route("/")       # decorator (/ page)
def time():
  now = datetime.now(timezone('America/New_York'))
  return "The current date and time in Cambridge is {}".format(now)
```

**Command line**
```
export FLASK_APP=application.py
  export FLASK_DEBUG=1
    flask run
```
- Saving in memory somewhere the location of the flask application stored in system variable
- FLASK_DEBUG=1: Something happen, it will show in debug mode

### Passing data
Data can be passed in via URLs, akin to using HTTP GET.
```python
@app.route("/show/<number>")
def show(number):
  return "You passed in {}".format(number)
```

Data can be passed in via HTML forms, as with HTTP POST\
We need to indicate that Flask should respond to HTTP POST requests explicitly.
```python
@app.route("/login", methods=['GET', 'POST']
def login():
  if not request.form.get("username")
    return apology("must provide username")
```

We could also vary the behavior of our function depending on the type of HTTP request received
```python
@app.route("/login", methods=['GET', 'POST'])
def login():
  if request.method == "POST":
    # do one thing
  else:
    # do a different thing
```

### Flask functions
| Function          	| Description                                                                                     	|
|-------------------	|-------------------------------------------------------------------------------------------------	|
| url_for()         	| Instead of specifying exact URL, go to the URL whatever the function it is (e.g. url(log_in())) 	|
| redirect()        	| Redirect from one page to another                                                               	|
| session()         	| Track if user is logged in, global variable                                                     	|
| render_template() 	| Create the page on the site that mixed together HTML with python                                	|

---

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
