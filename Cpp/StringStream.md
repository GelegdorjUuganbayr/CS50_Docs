# String Stream

 std::stringstream allows you to read and write data to/from a string
 - operator >> 
 - operator <<
 
 ## Interaction between string and stream
 ```cpp
#include <sstream>// For std::stringstream.
#include <string> // For std::string.
#include <iostream>   // For std::cout etc. 

std::stringstream stream;
stream << "Jane" << " " << 42 << " " << 15000 << std::endl; 

std::string name;
int age;
double salary;
stream >> name >> age >> salary;

std::cout
<< "Name: " << name << std::endl
<< "Age: " << age << std::endl
<< "Salary:" << salary << std::endl;
```

## Setting and Getting the Content of a String Stream
```cpp
// Create a stringstream object.
std::stringstream stream;

// Set the string content for a stringstream.
stream.str("Jane 42 15000");

// Get the content from a stringstream.
std::cout << "Content of string stream: " << stream.str() << std::endl;
```

## Creating a String Stream from an Existing String
The std::stringstream constructor allows you to create a string stream object from an existing std::string object.
- Overwriting an existing string with new content.
- Parsing an existing formatted string to extract values.

### Overwriting string using stream
```cpp
// Create a stringstream object to write to an existing string.
std::string str0 = "********************";
std::stringstream stream(str0);

// Do some output.
stream << "Jane" << " " << 42 << " " << 15000;

// See the effect.
std::cout << stream.str() << std::endl;
```
**output**
```
Jane 42 15000*******
```
The existing string contains 20 asterisk characters initially, and we overwrite some of this content with a person's name (Jane), age (42), and salary (15000):

### Extract values from string and store into stream
```cpp
// Create a stringstream object to read from an existing string.
std::string str0 = "Jane 42 15000";
std::stringstream stream(str0);

// Read formatted data from stringstream.
std::string name;
int age;
double salary;
stream >> name >> age >> salary;

std::cout
    << "Name: " << name << std::endl
    << "Age: " << age << std::endl
    << "Salary:" << salary << std::endl;
```
**output**
```
Name: Jane
Age: 42
Salary:15000
```
we create a std::stringstream object to parse an existing formatted string to extract values

## Write-Only and Read-Only String Streams
- std::ostringstream
  - Output characters to a string.
- std::istringstream
  - Input characters from a string.

```cpp
// Create an ostringstream object, which supports write-only operations.
std::ostringstream stream1;

stream1 << "Jane" << " " << 42 << " " << 15000 << std::endl;

// Create an istringstream object, which supports read-only operations.
std::istringstream stream2(stream1.str());

std::string name;
int age;
double salary;
stream2 >> name >> age >> salary;
```

## Wide Characters
wchar_t represents wide characters. Wide characters are useful if you need to represent non-roman character sets.
- std::wstring represents a string of wide characters.
- std::wistream, std::wostream, and std::wstream allow you to input and output wide characters. std::wcin and std::wcout are predefined instances of std::wistream and std::wostream respectively.
- std::wistringstream, std::wostringstream, and std::wstringstream allow you to input and output wide characters to/from a string.

```cpp
std::wstringstream stream;

stream << "Jane" << " " << 42 << " " << 15000 << std::endl;

std::wstring formattedString = stream.str();
std::wcout << formattedString;

std::wstring name;
int age;
double salary;
stream >> name >> age >> salary;

std::wcout
    << "Name: " << name << std::endl
    << "Age: " << age << std::endl
    << "Salary:" << salary << std::endl;
```

## Additional String Stream Operations
- std::istringstream inherits from std::istream.
- std::ostringstream inherits from std::ostream.
- std::stringstream inherits from std::iostream, which in turn inherits from both std::istream and std::ostream.
