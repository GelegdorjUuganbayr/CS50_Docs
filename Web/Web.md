# Internet Primer
> PHP, html, css

### IP Address
Internet Protocol, unique identifier of the computer on the network.
- In order for your machine to uniquely identify itself on the internet, it needs an address.
  - A computer can send out and receive information to the current location.
- IP addressing: The addressing scheme used by computers.

```
# IPv4 e.g.
w.x.y.z
123.45.67.89
```
- Each of w, x, y and z can be non-negative value in the range [0, 255]
- IP address is 32 bits (2 bytes x 4)
- New IP scheme (IPv6): Assign computers 128-bit addresses, instead of 32-bit addresses.

```
# IPv6 e.g.
s:t:u:v:w:x:y:z
1234:5678:90ab:cdef:fedc:ba09:8765:4321
2001:4860:4860:0:0:0:0:8844
2001:4860:4860::8844
```
- Each of s, t, u, v, w, x, y, and z is represented by 1 to 4 hexadecimal digits in the range[0, ffff]

### DHCP
Dynamic host configuration protocol server
- The task of assigning IP address fell to a system administrator, who would need to manually assign such addresses.
- Bank of IP address -> give it to a user

### DNS
The Domain Name System
- User never types in its IP address into the browser.
- DNS exists to help us translate IP address to more memorable names that are more human-comprehensible.
- DNS is somewhat like the yellow pages of the web.

|         Host         |   IPv4 Address  |
|:--------------------:|:---------------:|
|    info.host1.net    |     0.0.0.0     |
|    info.host1.net    |     0.0.0.1     |
|          ...         |       ...       |
| io-in-f138.1e100.net |  74.125.202.138 |
|          ...         |       ...       |
|   info.hostn-1.net   | 255.255.255.254 |
|    info.hostn.net    | 255.255.255.255 |

- There is really no DNS record of the entire internet.
- Large DNS server systems are more like aggregators.
  - Collecting smaller sets of DNS information and pooling them together, updating frequently.
  
### Access Point
- To deal with IPv4 addressing problem, starts assigning multiple people to the same IP address.
- The IP address is assigned to a router
  - Router: Act as a traffic cop that allows data requests from all of the devices on your local network (e.g. home) to be processed through a single IP address.\
    |device| <--private IP--> |router| <--public IP--> |internet|
- Modern home network consist of access points that combine a router, a modem, a switch, and other devices.
- Modern business networks of large-scale wide-area networks (WANs) still have these as seprarate devices to allow the size of their network to scale easily.

---

# IP
Internet Protocol
- Internet: Interconnected network comprised of smaller networks woven together and agreeing to communicate with on another.
- The way to know how to communicate with on another: This is the responsibility of the Internet Protocol (IP)

### Router
- Each network is connected to limited number of routers.
- Each router had instructions on how to move information toward its destination.
- This information might be stored in a routing table, inside of the router.
- The network are not directly connected to each other, and rely on routers to distribute communications.
- On a large scale, this configuration can dramatically reduce the costs of network infrastructure.

### IP
Move the infromation from the sending machine to a receiving machine.
- Getting information from A to B
- Split an infromation into packets (small peaces), so a network isn't overly tasked
- IP is also known as connectionless protocol. There is not necessarily a defined path from the sender to the receiver.
- Some packets can be "re-routed" around the traffic jam to follow the most optimal path, based on the current state of the network.

---

# TCP
Transmission Control Protocol
- Directing the transmitted packet to the correct program/service on the receiving machine
- Important to identify both:
  - where the receiver is
  - what the packet is for
- TCP and IP are almost an inseparable pair: TCP/IP

### port
- Program/service/utility on a machine is assigned a port number.
- Coupled with an IP address, we can uniquely identify a specific program on specific machine.
- TCP is crucial for **guaranteeing delivery of packets, which IP alone does not do.**
- TCP includes the information about how many packets the receiver is supposed to get, and what order, and transmitting that information alongside the data.

### TCP standardized port
- FTP: **21** - file transfer
- SMTP: **25** - e-mail
- DNS: **53** - Domain name system
- HTTP: **80** - Web browsing
- HTTPS: **443** - Secure web browsing

|   Packet    |
|:-----------:|
| Receiver IP |
| 25 / 1 of 4 |
|   \<DATA\>  |

---

# HTTP
Hypertext Transfer Protocol
- Application itself has a system of rules for how to interpret the data that was sent.
- HTTP is an application layer protocol
  - how one must make a request for a webpage
  - how a server/host werver delevers that information back to client
```
method request-target http-version
GET request-target HTTP/1.1
POST request-target HTTP/1.1
```
- The host name (domain name of the server) is also included as a separate line of the overall HTTP request.
- Taken together, the host name and the request target specify a specific resource being sought.
- Based on the resource status, a number of status codes ca result.

| Class        | Code | Text                  | Comments                                                             |
|--------------|------|-----------------------|----------------------------------------------------------------------|
| Success      | 200  | OK                    | All is well, valid request and response.                             |
| Redirection  | 301  | Moved Permanently     | Page is now at a new location. Automatic redirection.                |
| Redirection  | 302  | Found                 | Page is now at a new location temporarily.                           |
| Client Error | 401  | Unauthorized          | Page typically requires login credentials.                           |
| Client Error | 403  | Forbidden             | Server will not allow request.                                       |
| Client Error | 404  | Not Found             | Server cannot find what was asked for.                               |
| Server Error | 500  | Internal Server Error | Generic server failure in responding to the otherwise-valid request. |

---

# HTML
Hypertext Markup Language: A fundamental component of every website.
- It is a language, but it is not a program language.
  - It lacks concept of variables, logic, funtions, and the like.
- It is a markup language
  - Using angle-bracket enclosed tags to semantically defin the structure of a web page
  - Causing the plain text inside of sets of tags to be interpreted by web browsers in different ways.
```html
<html>
  <head>
    <title>
      Hello, world
    </title>
  </head>
  <body>
    World, hello
  </body>
</html>  
```
- head: make render correctly
- title: words for a tab of a browser
- body: contents
- The markup allows us to convey extra information about the text we've written.
- There are over 100 HTML tags, and lots of great resources online to find them.
- Another interesting way to learn about HTML tags is to view the source of a website you frequentl by opening up your browser of choice's developer tools.

### Common HTML tags

| Tag                      | Description                                                                                |
|--------------------------|--------------------------------------------------------------------------------------------|
| \<b\>, \</b\>            | Rendered in blodface by the browser.                                                       |
| \<i\>, \</i\>            | Rendered in italics by the browser.                                                        |
| \<u\>, \</u\>            | Rendered underlined by the browser.                                                        |
| \<p\>, \</p\>            | Rendered as a paragraph by the browser, with space above and below.                        |
| \<hX\>, \</hX>           | Rendered as an X-level section header. (X = 1,2,3,4,5, or 6)                               |
| \<ul\>, \</ul\>          | Unordered (bulleted) list.                                                                 |
| \<ol\>, \</ol\>          | Ordered (numbered) list.                                                                   |
| \<li\>, \</li\>          | Elements of ordered or unordered list.                                                     |
| \<table\>, \</table\>    | The beginning and end of a table.                                                          |
| \<tr\>, \</tr\>          | The beginning and end of a row within a table                                              |
| \<td\>, \</td\>          | The beginning and end of a column within a row within a table                              |
| \<form\>, \</form\>      | The beginning and end of an HTML form.                                                     |
| \<div\>, \</div\>        | The beginning and end of an arbitrary HTML page division.                                  |
| \<input name=X Type=Y/\> | Define a field within HTML form. X is a unique identifier, Y type of data it accepts.      |
| \<a href=X\>, \</a\>     | Creates a hyperlink to web page X, with the tags rendered and functional as the link text. |
| \<img src=X ... /\>      | Displaying an image located at X, with possible additional attributes                      |
| \<!DOCTYPE html\>        | Specific to HTML5, lets the browser know that's the standard you are using.                |

# CSS

Cascading Style Sheets
- Another language we use to when cunstructing websites.
- It is the tool we use to customize our website's look and feel.
- It is a styling language and its syntax decribes how certain attributes of HTML elements should be modified.

```CSS
body
{
  background-color: blue;
}
```

- A style sheet is constructed by a selector (body), then open curly brace to indicate the begin and end of the style sheet for that selector.
- Between the curly brace, key-value pairs of style properties and values for properties will be placed. Each declaration ending with a semicolon.

### Common CSS properties
**border: style color width**
- Applies a border of the specified color, width, and style (e.g., dotted, dashed, solid, ridge)

**background-color: [keyword | #<6-digit hex>]**
- Sets the background color. Some colors are pre-defined in CSS.

**color: [keyword | #<6-digit hex>]**
- Sets the foreground color (usually text).

**font-size: [absolute size | relative size]**
- Can use keywords (xx-small, medium...), fixed points (10pt, 12pt...), percentage (80%, 120%) or bas off the most recent font size (smaller, larger).

**font-family: [font name | generic name]**
- Certain "web safe" fonts are pre-defined in CSS.

**text-align: [left | right | center | justify]**
- For displaying text

```CSS
<ID>
#unique
{
  border: 4px dotted blue;
  text-aligh: right;
}

<class>
.students
{
  background-color: yellow;
  opacit: 0.7;
}
```

- The selectors don't have to apply only to HTML tag categories.
- ID selectors and class selectors.
- ID selector will apply only to an HTML tag with a unique identifier.
- class selector will apply only to those HTML tags that have been given identical class attrigutes.

Style sheet can be written directly into the HTML
- Place them within <style> tags within the page's head.
  
Style sheet also be written as separate CSS files and then linked in to the document.
- Use<link> tags within the page's head to accomplish this.


