# SQL
The structure Query Language
- Purpose is to query a database.
- **MySQLQuery** is tae you can establish the type of relational database that SQL is most adept at working with
- **phpMyAdmin** is GUI that used to execute database queries in a more user-friendly way

## Process
- Create a database
- Create a table
  - Doing this programmatically is odd, so phpMyAdmin comes in handy here
  - Specify all of the columns in the table
  - All queries will refer to rows of the table
  - Each column of the SQL table is capable of holding data with different type
- When constructing a table in SQL, choose one column to be the **primary key**
  - Primary keys enable rows to be **uniquely** and **quickly** identified
  - Joint primary key: a combination of two columns that is always guaranteed to be unique

### SQL type

|         	|   	        |          	|           	|           	|
|:--------:	|:---------:	|:-------:	|:---------:	|:----------:	|
|    INT   	|  SMALLINT 	| TINYINT 	| MEDIUMINT 	|   BIGINT   	|
|  DECIMAL 	|   FLOAT   	|   BIT   	|    DATE   	|    TIME    	|
| DATETIME 	| TIMESTAMP 	|   CHAR  	|  VARCHAR  	|   BINARY   	|
|   BLOB   	|    TEXT   	|   ENUM  	|  GEOMETRY 	| LINESTRING 	|

- CHAR: fixed-length string
  - CHAR(10): 10 characters string
- VARCHAR: variable-length string

### Type affinity

|     	|         	|      	|     	|     	|
|:----:	|:-------:	|:----:	|:----:	|:----:	|
| NULL 	| INTEGER 	| REAL 	| TEXT 	| BLOB 	|

### Four operation of SQL
- INSERT
- SELECT
- UPDATE
- DELETE

# Example
### users
| idnum 	| username  	| password 	| fullname        	|
|-------	|-----------	|----------	|-----------------	|
| 10    	| jerry     	| fus!ll!  	| Jerry Seinfeld  	|
| 11    	| gcostanza 	| b0sc0    	| George Costanza 	|

### moms
| username  	| mother           	|
|-----------	|------------------	|
| jerry     	| Helen Seinfeld   	|
| gcostanza 	| Estelle Costanza 	|

## INSERT
Add information to a table
```
INSERT INTO
<table>
(<columns>)
VALUES
(<values>)
```

### INSERT-users
```
INSERT INTO
users
(username, password, fullname)
VALUE
('newman', 'USMAIL', 'Newman')
```
### output

| idnum 	| username  	| password 	| fullname        	|
|-------	|-----------	|----------	|-----------------	|
| 10    	| jerry     	| fus!ll!  	| Jerry Seinfeld  	|
| 11    	| gcostanza 	| b0sc0    	| George Costanza 	|
| 12    	| newman    	| USMAIL   	| Newman          	|

- Usually good to have the primary key column as an integer
- You can configure a primary column to autoincrement
  - it will pre-populate that column automatically when rows are added to the table

## SELECT
Extract information from a table
```
SELECT
<columns>
FROM
<table>
WHERE
<condition>
ORDER BY
<column>
```

### SELECT-users
```
SELECT
idnum, fullname
FROM
users
```
### output
```
10 Jerry Seinfeld
11 George Costanza
12 Newman
```

### SELECT-condition-1
```
SELECT
password
FROM
users
WHERE
idnum < 12
```
### output
```
fus!ll!
b0sc0
```

### SELECT-condition-2 (*)
```
SELECT
*
FROM
moms
WHERE
username = 'jerry'
```

### output
```
jerry Helen Seinfeld
```

## Relationship table
- SELECT (JOIN)
```
SELECT
<columns>
FROM
<table1>
JOIN
<table2>
ON
<predicate>
```
### SELECT (JOIN)-users
```
SELECT
users.fullname, moms.mother
FROM
users
JOIN
moms
ON
users.username = moms.username
```

## UPDATE
Modify information in a table
```
UPDATE
<table>
SET
<column> = <value>
WHERE
<predicate>
```

### UPDATE-users
```
UPDATE
users
SET
password = 'yadayada'
WHERE
idnum = 10
```

## DELETE
Remove information from a table
```
DELETE FROM
<table>
WHERE
<predicate>
```

### DELETE-users
```
DELETE FROM
users
WHERE
username = 'newman'
```

# Interact with python
### print title of album
```python
import sys
from cs50 import SQL

db = SQL("sqlite:///lecture.db")

# Query database for all albums
rows = db.execute("SELECT * FROM Album WHERE Title = :title", title=sys.argv[1])

# For each album in database
for row in rows:

  # print title of album
  print(row["Title"])
```

### put data into the template
```python
from flask import Flask, render_template, request
from cs50 import SQL

app = Flask(__name__)
db = SQL("sqlite:///lecture.db")

@app.route("/")
def index():
  query = request.args.get("q")
  rows = db.execute("SELECT * FROM Album WHERE Title = :q", q=query)
  return render_template("index.html", albums=rows)
```

### index.html
``` html
{% block body %}
  
    {% for album in albums %}

        {{ album["Title"] }}

    {% endfor %}

{% endblock %}
```
