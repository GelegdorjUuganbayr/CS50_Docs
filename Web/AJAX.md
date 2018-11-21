# AJAX
### Asyncronous JavaScript and XML
- It allows to dynamically update a webpage even more dynamically
- Refresh sections of the page instead of entire page

### XMLHttpRequest
```javascript
var xhttp = new XMLHttpRequest()
```
- Asynchronously update the pages
- After obtainig new object, its **onreadystatechange** behaviour needs to be defined
  - When the asynchronous HTTP request has completed, this will be called.
  - It defines what is expected to change on the site
  - Do something whenever it detects the changes of the site
- Properties to detect when the page finishing loading
  - **readyState** will change from 0 (not initialized) to 1, 2, 3, 4 (request finished, response ready)
  - The **status** property will be 200 (ok)
- Asynchronous request
  - **open()**: define the request
  - **send()**: send the request

### JavaScript
```javascript
function ajax_request(argument)
{
  var aj = new XMLHttpRequest();
  aj.onreadystatechange = function() {
    if (aj.readyState == 4 && aj.status == 200)
      // do something to the page
  };
  
  aj.open("GET", /* url */, true);
  aj.send();
}
```
