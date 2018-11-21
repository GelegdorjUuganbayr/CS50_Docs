# Dom
Document Object Model
- Object that we can use to manipulate the data and content on our webpages
  - Document object have properties and methods
  - Resetting properties/Calling methods changes the contents of web pages

console.dir(document)
organise the contents of the page in a directory structure

## DOM Properties

| DOM Property 	| Description                                                   	|
|:------------:	|---------------------------------------------------------------	|
|   innerHTML  	| Holds the HTML inside a set of HTML tags                      	|
|   nodeName   	| The name of an HTML element of element's attribute.           	|
|      id      	| The "id" attribute of an HTML element.                        	|
|  parentNode  	| A reference to the node one level up in the DOM.              	|
|  childNodes  	| An array of reference to the nodes one level down in the DOM. 	|
|  attributes  	| An array of attributes of an HTML element.                    	|
| style        	| An object encapsulating the CSS/HTML styling of an element.   	|

## DOM Methods

|        DOM Methods        	| Description                                                       	|
|:-------------------------:	|-------------------------------------------------------------------	|
|     getElementById(id)    	| Gets the element with a given ID below this point in the DOM.     	|
| getElementsByTagName(tag) 	| Gets all elements with the given tag below this point in the DOM. 	|
|     appendChild(node)     	| Add the given node to the DOM below this point.                   	|
|     removeChild(node)     	| Remove the specified child node from the DOM.                     	|

## jQuery
- Start from document: we can get to any piece of the webpage through use of DOM properties and methods
- jQuery is a popular open-source library that is designed to simplify client-side scripting
- https://api.jquery.com

### JavaScript
```javascript
document.getElementById('colorDiv').style.backgroundColor = 'green'
```
### jQuery
```javascript
$('#colorDiv').css('background-color', 'green');
```

# Example

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


### from1.html (Register)
```html
<!DOCTYPE html>

<html>
    <head>
        <script src="form1.js"></script>
        <title>form1</title>
    </head>
    <body>
        <form action="/register" id="registration" method="get>
            <input autocomplete="off" autofocus name="email" placeholder="Name" type="text"/>
            <input name="password" placeholder="Password" type="password"/>
            <input name="confirmation" placeholder="Password (agina)" type="password"/>
            <input name="agreement" type="checkbox"/> I agree
            <input type="submit" value="Register"/>
        </form>
    </body>
</html>
```

### form1.js
```javascript
let form = document.getElementById("registration)";
form.onsubmit = function() {
    if(!form.email.value)
    {
        alert("missing email");
        return false;
    }
    else if(!form.password.value)
    {
        alert("missing password");
        return false;
    }
    else if(form.password.value.length < 8)
    {
        alert("password too short");
        return false;
    }
    else if(form.password.value != form.confirmation.value)
    {
        alert("passwords don't match");
        return false;
    }
    else if(form.agreement.checked)
    {
        alert("checkbox unchecked");
        return false;
    }

    return true;
};
````
- recursivly download the java script file
