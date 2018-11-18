# Class
## Constructor
A constructor is used to initialize data members of a class.
- The format is that it contains the same name as the class itself, has no return type, and may or may not contain a parameter list.
- Classes can have multiple constructors.
- Constructors can be overloaded in the same way that functions can be overloaded.
- If you don't create a constructor in your class file, the compiler will create a default constructor automatically that will initialize member variables to default values.
- A class has one default constructor. If you create any other constructor in your class, then the compiler will not create one.
- If you require or want a default constructor as well as other constructors, then you MUST create your own default constructor.

### Default constructor
```cpp
class Person
{
public:
    Person();
    ~Person();
};
```

Two more reasons for defining a default constructor in your classes
- Compound types (arrays or pointers) that may be defined inside a code block, can have undefined values when initialized to their default values.
  - You should ensure that these members are initialized correctly by creating your own default constructor and performing the initialization yourself.
- Another reason arises when the class contains a member that is a class itself.
  - The compiler's default constructor is unable to initialize that member.
  
## Person.h
```cpp
#pragma once
#include <string>

class Person
{
private:
    std::string firstName;
    std::string lastName;
    int age;
public:
    Person();
    Person(std::string fName, std::string lName);
    Person(std::string fName, std::string lName, int age);
    ~Person();

    void SayHello();
};
```

## Person.cpp
```cpp
#include "stdafx.h"
#include "Person.h"
#include <iostream>

Person::Person()
{
}

Person::Person(std::string fName, std::string lName)
{
    this -> firstName = fName;
    this -> lastName = lName;
}

Person::Person(std::string fName, std::string lName, int age)
{
    this -> firstName = fName;
    this -> lastName = lName;

    this -> age = age;
}

Person::~Person()
{
}
```

**Person::Person()**
- It has no parameters and private member variables are not initialized. 
- This constructor will do so with the default values for data types of those member variables.

**Person::Person(std::string fName, std::string lName)**
- It takes two arguments and uses those to initialize the first and last name member variables in the class. 
- age may or may not get initialized.


**Person::Person(std::string fName, std::string lName, int age)**
- It takes three arguments to initialize all three member variables.

When you create a new instance of the Person class, you can choose any of these constructors and the compiler will know which one to use based on the number of arguments you pass

## Main.cpp
```cpp
#include "stdafx.h"
#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    // create a Person instance using default constructor
    Person *pOne = new Person();

    // Create a Person instance using 2 argument constructor
    Person *pTwo = new Person("Tom", "Thumb");

    // Create a Person instance using 3 argument constructor
    Person *pThree = new Person("Tom", "Thumb", 15);

return 0;
}
```
