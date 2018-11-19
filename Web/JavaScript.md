# Java Script

### function
```javascript
function(bar, baz)
{
  ...
}
```
- Function does not have name.

### variable
```javascript
let i = 0;
```
- Variable does not have strict data type

### do while loom
```javascript
do
{
  ...
}
while(true);
```

### for loop
```javascript
for (let value of array)
{
  ...
}
```
- Iterate value in an array

### if else statement
```javascript
if (x < y)
{
  ...
}
else if (x > y)
{
  ...
}
else
{
  ...
}
```

### array
```javascript
let numbers = [4, 8, 15, 16, 23, 42];
var numbers = [4, 8, 15, 16, 23, 42];
```
- array can be resized (shirink, expand)

### object (dictionary)
```javascript
let quote = {
  name: "Netflix, Inc.",
  price: 199.32,
  symbol: "NFLX"
};
```
- data structure
- 

### Dom Bad
```html
<!DOCTYPE html>

<html>
    <head>
        <script>
            function greet()
            {
                alert("hello, world");
            }
            
        </script>
        <title>dom0</title>
    </head>
    <body>
        <form id="demo" onsubmit="greet(); return false">
            <input autocomplete="off" autofocus id="name" placeholder="Name" type="text"/>
            <input type="submit"/>
        </form>
    </body>
</html>
```
**alert("hello, world");**
- print out in a new window

**<form id="demo" onsubmit="greet(); return false">**
- on submission of this, call greet()
- return false: stay as it is, not doing anything

**<input autocomplete="off" autofocus id="name" placeholder="Name" type="text"/>**
- autocomplete="off": disable autocomplete of text box
- autofocus: automatically locate the cursor in the box

### Dom Good
```html
<!DOCTYPE html>

<html>
    <head>
        <title>dom0</title>
    </head>
    <body>
        <form id="demo">
            <input autocomplete="off" autofocus id="name" placeholder="Name" type="text"/>
            <input type="submit"/>
        </form>
        <script>
            function greet()
            {
                alert("hello, world");
            }
            
            document.getElementById("demo").onsubmit = greet;
        
        </script>
    </body>
</html>
```

**document.getElementById("demo").onsubmit = greet;**
- document: global variable for the page that I am writing
- document.getElementById("demo"): grab the demo from this page and do something
- .onsubmit: event handler, submit it
- greet: omit the parentesis - doesn't call it right away, when the format is submitted, call greet instead of run the function right away.

### Pass function now and call it later
```javascript
function greet()
{
    alert("hello, world");
}

document.getElementById("demo").onsubmit = greet;
```

```javascript
document.getElementById("demo").onsubmit = function() {
    alert("hello, world");
};
```

### Submit the form
```javascript
document.getElementById("demo").onsubmit = function() {
    let name = document.getElementById("name").value;
    alert("hello, " + name);
    alert(`hello, ${name}`);
};
````
**alert(`hello, ${name}`);**
- template literal, plug the value of variable


