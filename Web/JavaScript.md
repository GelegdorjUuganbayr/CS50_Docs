# Java Script
## Including the JavaScript in HTML
- Write the JavaScript between <script> tags (Like <style> of CSS)
- You can write JavaScript in separate files and link in by using the src attribute of <script> tag.

## variable
Similar to Python variables
- No type specifier
- Declare local variable: **var** keyword
```javascript
var x = 44;
let i = 0;
```
- Variable does not have strict data type
- var: local variable

## Conditionals - if else statement
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

## Loop
### do while loop
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

## function
- All functions are introduced with the function keyword
- JavaScript functions can be anonymous - Don't have to give them a name
```javascript
function(bar, baz)
{
  ...
}
```

## array
- elements type can be mixed
- array can be resized (shirink, expand)
  - array.size(), array.pop(), array.push(x), array.shift()
```javascript
let numbers = [4, 8, 15, 16, 23, 42];
var numbers = [4, 8, 15, 16, 23, 42];
var mixed = [1, true, 3.333, 'five'];
```

## object (dictionary)
- C structure contain a number of fields or members (properties)
  - properties themselves can not stand on their own
  - object.attribute
- Objects have methods that are only inherent to the object
  -object.method()
```javascript
let quote = {
  name: "Netflix, Inc.",
  price: 199.32,
  symbol: "NFLX"
};
```

## Looping a object
### Printing a key
```javascript
var wkArray = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'];

for (var day in wkArray)
{
   console.log(day);
   console.log(wkArray[day] + ' is day number '
              + (parseInt(day) + 1) + ' of the week!');
}
```
### Result
```
0 1 2 3 4 5 6
```

### Printing a value
```javascript
for (var day of wkArray)
{
   console.log(day);
}
```
### Result
```
Mon Tue Wed Thu Fri Sat Sun
```

## map()
Apply a function to all elements of an array
```javascript
var nums = [1,2,3,4,5];

nums = nums.map(function(num))
{
  return num * 2;
}
```

## Events
- event in HTML/JavaScript is a response to user interaction with the web page.
  - user clicks a button, finishing loading a page, user has hovered over a portion of the page, user typed in an input field.
- event handlers: call back functions that respond to HTML events
  - Many HTML elements have support for events as an attribute

### HTML
```html
<html>
    <head>
        <title>Event Handlers</title>
    </head>

    <body>
        <button onclick="alertName(event)">Button 1</button>
        <button onclick="alertName(event)">Button 2</button>
    </body>
</html>
```
- **onclick=""**: event handler
- Either button 1 or button 2 is clicked, alertName function will be called and event will be passed in
- Event is automatically generated by page and contains every information just happend

### JavaScript
```javascript
function alertName(event)
{
  var trigger = event.srcElement;
  alert('You clicked on ' + trigger.innerHTML);
}
```
- event.srcElement
  - what is the element on the page that is interacting with the trigger this event
  - what element affectively was passed in to this function
- innerHTML
  - which button you clicked on

---

# Additional
### pop-up
```html
<html>
  <head>
    <script>
      
      alert("hello, world");
      
    </script>
  </head>
  <body>
    <form id="demo">
      <input id="name" placeholder="Name" type="text"/>
      <input type="submit"/>
  </body>
</html>
```

### function - bad practice
- two different language in a line
```html
<html>
  <head>
    <script>
      
      function greet()
      {
        alert("hello, world");
      }
      
    </script>
  </head>
  <body>
    <form id="demo" onsubmit="greet(); return false;">
      <input autocomplete="off" autofocus id="name" placeholder="Name" type="text"/>
      <input type="submit"/>
    </form>
  </body>
</html>
```
- return false: stay in where user is
- autocomplete: history of what user typed
- autofocus: automatically put cursor in the field

### function - intermediate practice
```html
<html>
  <head>
    <title>Demo</title>
  </head>
  <body>
    <form id="demo" onsubmit="greet(); return false;">
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
- \<form id="demo"\>
- document.getElementById("demo").onsubmit
  - when form "demo" is on submit
- greet
  - not greet(), so it doesn't call the function right away
  - just let browser know when the function called, implement it

### Anonymous function
```html
document.getElementById("demo").onsubmit = function() {
  let name = document.getElementById("name").value;
  alert("hello, " + name);
  alert(`hello, ${name}`};
};
```
- alert(`hello, ${name}`};
  - template literal in JavaScript

## Feedback through new window
### form1.html
```html
<html>
  <head>
    <script src="form1.js"></script>
    <title>form1</title>
  </head>
  <body>
    <form action="/register" id="registration" method="get">
      <input autocomplete="off" autofocus name="email" placeholder="Email" type="text"/>
      <input name="password" placeholder="Password" type="password"/>
      <input name="confirmation" placeholder="Password (again)" type="password"/>
      <input name="agreement" type="checkbox"/> I agree
      <input name="submit" value="Register"/>
    </form>
  </body>
</html>
```

### form1.js
```javascript
let form = document.getElementById("registration");
form.onsubmit = function() {

  if (form.email.value == "")
  {
    alert("missing email");
    return false;
  }
  else if (form.password.value == "")
  {
    alert("missing email");
    return false;
  }
  else if (form.password.value != form.confirmation.value)
  {
    alert("passwords don't match");
    return false;
  }
  else if (!form.agreement.value)
  {
    alert("checkbox unchecked");
    return false;
  }

  return true;
}
```

## jquery
```html
<html>
  <head>
    <script src="https://code.jquery.com/jquery-latest.min.js"></script>
    <script>
      jQuery(document).ready(function() {
        $("#registration").submit(function() {
          if(!$("#registration input[name=email]").val())
          {
            alert("missing email");
            return false;
          }
      }
    </script>
    <title>form1</title>
  </head>
  <body>
    <form action="/register" id="registration" method="get">
      <input autocomplete="off" autofocus name="email" placeholder="Email" type="text"/>
      <input name="password" placeholder="Password" type="password"/>
      <input name="confirmation" placeholder="Password (again)" type="password"/>
      <input name="agreement" type="checkbox"/> I agree
      <input name="submit" value="Register"/>
    </form>
  </body>
</html>
```
- jQuery(document).ready(function()
  - take function when it is ready
  - take function when the document is ready
- $("#registration").submit(function()
  - document.getElementById("registration").onsubmit
- #registration
  - id is registration
- input
  - get input attribute
- value
  - get value
