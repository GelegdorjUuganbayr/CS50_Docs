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

## Quote on window

### version0
```html
<html>
  <head>
    <script src="https://code.jquery.com/jquery-latest.min.js"></script>
    <script>
      
      function quote()
      {
        $.getJSON("/quote", {symbol: $("#symbol").val()}, function(data) {
          alert(data.price);
        });
      }
      
    </script>
    <title>form1</title>
  </head>
  <body>
    <form onsubmit="quote(); return false;">
      <input autocomplete="off" autofocus id="symbol" placeholder="Symbol" type="text"/>
      <input type="submit" value="Get Quote"/>
    </form>    
  </body>
</html>
```
- quote(); return false;
  - Do not reload the page and Do not submit the form for real
  - Just call the quote() function
- $.getJSON
  - jQuery.getJSON
- "/quote"
  - get the data from /quote
- function(data)
  - when the data is ready, call back
  
### version1
```html
<script>
  
  $(document).ready(function() {
    
    $('#quote').submit(function() {
  
      $.getJSON("quote", {symbol: $("#symbol").val()}, function(data) {
        alert(data.price);
      });
      return false;
  
    });
  });
</script>
```
### Same codes
```html
let http_parameters = {
  symbol: $("#symbol").val()
  symbol: document.getElementById("symbol").value
};
$.getJSON("quote", http_parameters, function(data)
```

```html
$.getJSON("quote", {symbol: $("#symbol").val()}, function(data) {
  alert(data.price);
});
````

## Navigator (Asyncronisys)
```html
<script>
  
  navigator.geolocation.getCurrentPositioin(function(position) {
    document.write(position.coords.latitude + ', ' + position.coords.longitude);
  });
  
</script>
```
- navigator.geolocation.getCurrentPositioin
  - get user's current Location
  
## Blink
```javascript
function blink()
{
  var div = document.getElementById("greeting");
  if(div.style.visibility == "hidden")
  {
    div.style.visibility = "visible";
  }
  else
  {
    div.style.visibility = "hidden";
  }
}

// blink every 500ms
window.setInterval(blink, 500);
```

## Map
```html
<html>
  <body>
    <div id="map"></div>
    <script>

      function initMap()
      {
        let map = new google.maps.Map(document.getElementById("map"), {
          center: {lat: 39.833, lng: -98.583},
          zoom: 4
        });
      
        new google.maps.Marker({
          map: map,
          position: {lat: 42.3762, lng: -71.1158}
        });
      
        new google.maps.Marker({
          map: map,
          position: {lat: 41.3104, lng: -72.9289}
        });
      
      }
      
    </script>
    <script src="https://maps.googleapis.com/maps/api/js?key=blahblahblah"/>
  </body>
</html>
            
```
