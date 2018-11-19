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

## Destructor
Destructor cannot have any arguments passed in to it. Therefore, when writing your own destructors, you should not place arguments between the parentheses for the destructor.

# Dynamic Memory Allocation
**new**
- It is used to allocate memory for an object at runtime 
**delete**
- It is used to release that memory

```cpp
Person *pOne = new Person();
Person *pOne = new Person("Gerry", "O\'Brien");

std::cout << pOne->GetLastName() << endl;

// delete object, releasing memory
delete pOne;
```

## namespace
For classes with names that conflict with those in the STL or with other code, C++ uses namespaces to help resolve these conflicting issues.

- A namespace is a "scope container" where you can place your classes, variables, or other identifiers to prevent conflicts with others.
- Anytime you want to reduce ambiguity or name collisions, you use the namespace designator ahead of the identifier.
- The :: is the scope resolution operator and allows you gain access to the cout function in the std namespace. (e.g. std::cout)
  - you would call the C++ version using std::cout and your version using myNS::cout.

C++ also permits the use of using statement to help reduce the amount of code that you have to tyep when classes are inside a namespace.
```cpp
using namespace std;
```

- By doing this, you can now simple use cout << "Hello"; in your code instead of typing the namespace and scope resolution operator, saving you some keystrokes.
- However, take note that you cannot apply using statement if there is a chance of ambiguity in the code.

### Illegal namespace usage example
```cpp
using namespace std;
using namespace myNS;

int main()
{
    cout << "std version of cout";
    cout << "myNS version of cout";
}
```

### Proper namespace usage example
```cpp
using namespace std;

int main()
{
    cout << "std version of cout";
    myNS::cout << "myNS version of cout";
}
```

### Defining namespace
- You can define your own namespace by using the keyword namespace, followed by the chosen name and then enclosing your code within the curly braces.
- You also have the option of creating nested namespaces if you choose to provide more separation of identifiers in your code.
```cpp
namespace Microsoft
{
    namespace Geometry
    {
        const double PI = 3.14159;
        double Area(double radius)
        {
            return PI*(r*r);
        }
    }
}
```

### main.cpp
```cpp
int main()
{
    double radius = 12.5;
    double area = Microsoft::Geometry::Area(radius);
}
```

---

# Inheritance
New classes can be derived from existing classes using a mechanism called "inheritance".
- base class: Classes that are derived FROM
- sub-class: Derived classes

```cpp
// Base Class
class Vehicle
{ 
    private:
       string Make;
       string Color;
       ...
}; 

// Sub Class
class Car: Vehicle
{ 
     // member list includes Make and Color
     // other Car specific members would go here.
};
```

C++ supports three different forms of inheritance
- public: how a derived class inherits all the member variables of a base class
- private: only able to directly access the public members of the base class
- protected: only able to directly access the public members of the base class

### Person.h
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

### Student.h
```cpp
#pragma once
#include "Person.h"

class Student : public Person
{
public:
    Student();
    ~Student();
};
```

**class Student : public Person**
- <:> This indicates that Student is a derived class of Person using public inheritance.
- Note that the Student class contains a default constructor and a destructor.

### Student.cpp
```cpp
#include "stdafx.h"
#include "Student.h"

Student::Student()
    : course("[Unassigned course]")
{
}

Student::Student(const std::string & name, int age, const std::string & course)
    : Person(name, age), course(course)
{
}

Student::~Student()
{
}

// this line will cause a compiler error    
firstName = "Tom";
```

**Student::Student()**
- Automatically use default constructor of Base class + course

**: Person(name, age), course(course)**
- It does have a base constructor, so it calls base constructor and add course(course)

### Main.cpp
```cpp
#include "stdafx.h"
#include "Person.h"
#include "Student.h"

int main()
{

    Student student1;

    // this line will generate a compiler error
    student1.firstName = "Tom";

    // this line is ok
    student1.SayHello();


    return 0;
}
```

**student1.firstName = "Tom";**
- Generate a compiler error even though Student has inherited the firstName member variable from Person. 
    - firstName member variable is declared as private in Person

**student1.SayHello();**
- function call will work as SayHello() is a public function

Providing public getters and setters for these private member variables is the proper way to gain access to private and protected from outside the class.
```cpp
Student::Student():Person("Tom", "Thumb")
{
}
```

## Protected
- keep certain members of the base class private to the "outside world" 
- keep certain members of the base class public to derived classes of that base class

### Person.h
```cpp
class Person
{
private:
    std::string firstName;
    std::string lastName;

protected:
    int age;

public:
    Person();
    Person(std::string fName, std::string lName);
    Person(std::string fName, std::string lName, int age);
    ~Person();

    void SetFirstName(std::string fName);
    std::string GetFirstName();
    void SetLastName(std::string lName);
    std::string GetLastName();
    void SayHello();
};
```

### Student.cpp
```cpp

Student::Student()
{
}

Student::~Student()
{
}

void Student::setAge(int age)
{
    if (age < 5)
    {
        std::cout << "Student age needs to at least 5 years old." << std::endl;
    }
    else
    {
        this->age = age;
    }
}

int Student::getAge()
{
    return this->age;
}

void Student::SayHello()
{
    std::cout << "Hey, how's it goin'?" << std::endl;
}
```

---

# Friend

## Friend Function
This allows the friend function to access all the members of the class, including private members. Friend functions are non-members, which means they don't receive a "this" pointer. Consequently, they must require an explicit parameter to access an object. 

### MyClass.h
```cpp
class MyClass
{
    friend void SomeExternalFunction(MyClass & targetObject);
    
    // Data members and member functions, as required.
    ...
};
```

### MyClass.cpp
```cpp
#include "MyClass.h"

void SomeExternalFunction(MyClass & targetObject)
{
    // Access any members on the target object, i.e. public, private, or protected members.
    ...
}
```
- Typically, you put friend function implementations in the same source file as member function implementations, because they are all part of the semantic meaning of the same class. 
- However you don't prefix friend functions with the ClassName:: syntax, because they are not members of the class:

## Friend Classes
A class can define another class as its friend. A friend class can access all the members of the first class. This is useful if you have a "binary system", that is two classes that are intimately related to each other.

### Body.h
```cpp
class Handle;

class Body
{
    friend class Handle;
    
private:
    int someData;
};
```

### Handle.h
```cpp
#include "Body.h"

class Handle
{
private:
    Body *body;
public:
    Handle();
    ~Handle();
    
    void someOperationOnBody();
}
```

### Handle.cpp
```cpp
#include "Handle.h"

Handle::Handle()
{
    body = new Body;
}

Handle::~Handle()
{
    delete body;
}

void Handle::someOperationOnBody()
{
    body->someData = 42;
}
```

---

# Virtual Function
One of the reasons for using inheritance is to reuse common code across a hierarchy of related classes. 
- Overriding: the derived classes need to implement specialized versions of some member functions from the base class.

### Person
```cpp
/* Person.h */
class Person
{
private:
    std::string name;
    int age;

public:
    virtual void display() const;        // Overrideable function.
    ...
};

/* Person.cpp */
void Person::display() const
{
    std::cout << name << ", " << age << std::endl;
}
```

**Overriding Virtual Function**
- When you define a derived class, you can optionally choose to override some or all of the virtual functions defined in the base class. Note that you don't have to override virtual functions if you don't want to. 
- To override a virtual function in a derived class, re-declare the function in the derived class header file.
- The function signature must match that in the base class.

### Student
```cpp
/* Student.h */
class Student : public Person
{
private:
    std::string course;

public:
     virtual void display() const;     // Override function from base class.
    ...
};

/* Student.cpp */
void Student::display() const
{
    // Call base-class version of display(), to display person-related info.
    Person::display();

    // Now display the student-related info.
    std::cout << course << std::endl;
}
```

## Virtual Constructor and Destructor
```cpp
class Person
{
public:
    virtual ~Person();
}
```

```cpp
// A base-class pointer can point to that type of object, or to any derived type of object.
Person * p1 = new Person;
Person * p2 = new Student;
```

```cpp
// Declare a pointer of type Person, which actually points to a Student object.
Person * p = new Student;

// Call the virtual display() function. This will call the Student display() function, 
// because that's the type of object p points to at run time.
p->display();
```
