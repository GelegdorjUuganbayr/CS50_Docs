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
- Getting information from A to B
- Split an infromation into packets (small peaces), so a network isn't overly tasked
- IP is also known as connectionless protocol. There is not necessarily a defined path from the sender to the receiver.
- Some packets can be "re-routed" around the traffic jam to follow the most optimal path, based on the current state of the network.
