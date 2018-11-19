# Stream
C++ defines a standard iostream library, which allows you to input and output data to the console using << operator and >> operator.
- cin is an instance of the istream class, and allows you to perform input from the stdin device.
- cout is an instance of the ostream class, and allows you to perform output to the stdout device. 
- cerr is another instance of the ostream class, and allows you to perform output to the stderr device. 

### String
```cpp
#include <iostream>
#include <string>
…
std::string s;
std::cin >> s;
std::cout << "Your string is " << s << std::endl;

std::getline(std::cin, name);
```
- Note that the >> operator inputs a single word
- It stops at the first whitespace character.
- If you want to input an entire line of text, you should use the std::getline() function instead.
  - parameter1: The input stream, from which you want to get the input
  - parameter2: The std::string object, into which you want to store the value
  
### istream for a class
```cpp
 class point
{
public:
    int x, y;

    // Plus other members, as appropriate.
};

// Defining a custom operator>>
std::istream & operator>> (std::istream & is, point & p)
{
    is >> p.x >> p.y;
    return is;
}
```
- The function must be named operator >>
  - This is an example of operator overloading
- The function must receive two parameters.
  - std::istream reference, and represents the input stream from which the values will be obtained
  - a point reference here, and represents the object that will be populated with input from the stream
- The function must return a std::istream object by reference

### ostream for a class
```cpp
std::ostream & operator << (std::ostream & os, const point & p)
{
    os << "[" << p.x << "," << p.y << "]";
    return os;
}
```
- The function must be named operator <<
- The function must receive two parameters
  - std::ostream reference, and represents the output stream where values will be output
  - const point reference here, and represents the object that will be output to the stream
- The function must return a std::ostream object by reference.

## Manipulator
**std::endl**
- output an end-of-line character:

**std::flush**
- flush its internal buffer to the physical device immediately
- This is useful if you are displaying debugging information, because it ensures your debug message is displayed immediately 
  - (e.g. before the program might crash later on)

### #include \<iomanip\>
Necessary for parameterized manipulators.
6 is significant default format

**std::cout << std::setw(n)**
- Setting the field width n
- Does not cause truncation

**std::cout << std::left**
- left-justified

**std::cout << std::right**
- right-justified

**std::cout << std::fixed**
- Always displays a number, a decimal point, and a fraction part. For examle, it never uses scientific format such as 1.23e5

**std::cout << std::scientific**
- Always uses scientific format such as 1.23e5

**std::cout.unsetf(std::ios::fixed | std::ios::scientific);**
- re-establish the general formatting
  
**std::cout << std::setprecision(n)**
- set precision as 4

**std::cout << std::showpos;**\
**std::cout << std::noshowpos;**
- specify whether you want the + sign to be displayed alongside positive numbers.

**std::cout << std::dec**
- numbers should be formatted in decimal

**std::cout << std::oct**
- numbers should be formatted inoctal

**std::cout << std::hex**
- numbers should be formatted inhexadecimal

**std::cout << std::showbase**
- it causes the number base to be displayed alongside numbers
  - a leading 0 for octal numbers, and a leading 0x for hexadecimal numbers



