# Classes that use shared representation objects
When we want to share one object between many other objects we need to keep a count of how many objects are using that instance
- Otherwise when it is destroyed all the other objects referencing it will break when they try to use it
- This concept is called reference counting
- The best solution is to store the counter on the object and increment it each time a new reference is made to the object
- The polymorphic way to do this is to create a class for reference counting which has functions to increment and decrement the counter and use this as a base class for classes that need reference counting
```cpp
//Reference counter base class.
class refCounter {

private:
	//The counter.
	int count;

public:

	//Constructor initialis count to 1.
	refCounter() : count(1){}

	//Increment count variable
	void increaseCount() {
		count++;
		cout << "increaseCount called count is " << count << "\n";
	}

	//Decrement count variable.
	int decreaseCount() {
		return --count;
		cout << "decreaseCount called count is " << count << "\n";
	}
};
```
So this small class contains:
- one private member which is the counter variable
- two public functions to increment and decrement the variable and a constructor
- we could inherit this class directly in the class we want to reference count
  - then call the increaseCount and decreaseCount functions in the copy constructor and copy assignment operators
  - or we could make a template class to do this for us and then when ever we want to reference count an object we just wrap it in the template class

### base class
```cpp
template< class referencedObject >
class ReferencedObject {

private:
	//The object being referenced.
	referencedObject *refObject;

	//Private destructor throws exception.
	void destructor() throw () {
		if (refObject != NULL && refObject->decreaseCount() == 0) {
			cout << "referenced object pointer being deleted. \n";
			delete refObject;
			refObject = NULL;
		}
	}

public:
	//Empty dummy class to throw
	class classToThrow {};

	//Constructor
	ReferencedObject(referencedObject *newObj = NULL) : refObject(newObj) {}

	//Invocation operator
	referencedObject *operator-> () throw (classToThrow) {
		if (!refObject) {
			throw classToThrow();
		}
		return refObject;
	}

	ReferencedObject< referencedObject > &operator= (ReferencedObject< referencedObject > &rhs) {

		//Check if same object if so return.
		if (this == &rhs) {
			return *this;
		}

		//Increment reference count.
		if (rhs.refObject) {
			rhs.refObject->increaseCount();
		}

		//Destroy current refObject which decrease reference count.
		destructor();

		//Assign new refObject to private member refObject.
		refObject = rhs.refObject;

		//Return object.
		return *this;
	}	

	//Destructor calls private destructor which can throw exception from delete.
	~ReferencedObject< referencedObject >() {
		cout << "ReferencedObject destructor called \n";
		destructor();
	}
};
```
- So this template class takes one template argument which is the type of the object we want to reference count
- The private members are a pointer to the object being reference counted and a destructor which deletes the pointer if the reference counter is zero
- The public functions consist of a dummy class to be thrown as an exception if for some reason the internal pointer becomes null
- The constructor which initialises the private reference pointer
  - Then the invocation operator which returns the private pointer
- The assignment operator is also defined
  - This does the standard self reference check and then increments the reference counter on the argument object
  - The destructor is then called on the current object which decrements the reference count to this object and then deletes the object if the count is zero
- Next it assigns the private pointer to the argument and returns
- The final function is the destructor which call the private destructor since the delete operator call can throw and exception and destructor's are not allowed to throw exceptions

### Inherits the base class
```cpp
class SharedObject : public refCounter {

public:
	SharedObject() {
		std::cout << "SharedObject created" << std::endl;
	}

	void SharedObjectAccess(const char *src) {
		cout << "SharedObjectAccess called parameter argument is " << src << "\n";
	}

	~SharedObject() {
		std::cout << "SharedObject destroyed" << std::endl;
	}
};
```

### main
```cpp
int main(int argc, char* argv[]) {

	//Create referenced object.
	ReferencedObject< SharedObject > ref(new SharedObject());

	//Invocation access
	ref->SharedObjectAccess("Hello World !!!");

	cout << "copying ref will increase counter \n";

	ReferencedObject< SharedObject > ref2(new SharedObject());
	ref2 = ref;

	//Invocation access
	ref2->SharedObjectAccess("Hello from ref2");

	cout << "\n\n";
	//Indirection access
	cout << "ref val called via indirection operator is " << (*ref).getVal() << "\n\n";

	return 0;
}	
```

# Interfaces
An interface is used to define the behaviour of classes without saying how to implement it
- interface are implemented using abstract classes
	- A class is made abstract by declaring at least one of it's functions as being pure virtual
	- A function is declared to be pure virtual if it has “=0” at the end of it's declaration
	- An abstract class contains generalizations about the characteristics of related entities.
- These entities derive the abstract base class and implement the pure virtual functions
- Abstract base classes cannot be instantiated and any attempt to do so will result in a compiler error

```cpp
#include <iostream>

using namespace std;

template<class type>
class Shape {

	//pure virtual function
	virtual type area() = 0;
 
};

template<class type>
class Rectangle : public Shape<type>
{
private:
	type width, height;
public:
	Rectangle(type wd,type hg) : width(wd),height(hg) {}
	type area()
	{
		return (width * height);
	}
	void setWidth(type wd) {
		width = wd;
	}
	void setHeight(type hg) {
		height = hg;
	}
};

template<class type>
class Triangle : public Shape<type>
{
private:
	type base, altitude;
public:
	Triangle(type ba,type alt) : base(ba),altitude(alt) {}
	type area()
	{
		return (base * altitude) / 2;
	}
	void setBase(type ba) {
		base = ba;
	}
	void setAltitude(type alt) {
		altitude = alt;
	}
};

int main(int argc, char* argv[]) {

	Rectangle<int> rect(5,5);
	Triangle<float> tri(3.3,6.5);

	//Helper function.
	rect.setWidth(3);

	cout << "Rectangle area is " << rect.area() << "\n";
	printf("Triangle area is %f \n",tri.area());

	return 0;
}
```

# Multiple inheritance

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class type>
class Shape {

	//pure virtual function
	virtual type area() = 0;

};

class drawShape {

	virtual void draw() = 0;

};

template<class type>
class Rectangle : public Shape<type>, public drawShape
{
private:
	type width, height;
public:
	Rectangle(type wd, type hg) : width(wd), height(hg) {}
	type area()
	{
		return (width * height);
	}
	void setWidth(type wd) {
		width = wd;
	}
	void setHeight(type hg) {
		height = hg;
	}
	void draw() {
		string lhs,spaces,line;

		for (int i = 0; i < width;i++) {
			spaces = spaces + "  ";
			line = line + "--";
		}

		for (int i = 0; i <= height; i++) {
			if (i == 0) {
				//top line
				lhs = lhs + "|" + line + "|\n";
			}
			else if (i == height) {
				//bottom line
				lhs = lhs + "|" + line + "|\n";
			}
			else {
				lhs = lhs + "|" + spaces + "|\n";
			}
		}
		
		cout << lhs.c_str();
		cout << "\n\n";
	}
 

};
```

# Virtual base classes
One issue that can arise with multiple inheritance is the diamond problem
- this is when there is a circular dependency among the inherited classes
- Now we create a class called CB that inherits both B and C then the compiler needs to work out if we are calling a function in A::B::CB or A::C::CB
- This situation can usually be resolved by using the virtual keyword when inheriting such as public virtual A
```cpp
#include <iostream>

using namespace std;

class A {
public:

	void printName() {
		cout << "A\n";
	}
};

class B : public A {};
class C : public A {};
class CB : public B, public C {};

class D : public virtual A {};
class F : public virtual A {};
class DF : public D, public F {};

int main(int argc, char* argv[]) {

	CB cb;
	//cb.printName();  //Compiler error ambigous printName

	DF df;
	df.printName();

	return 0;
}
```
- The above code shows the diamond problem and the solution
- class CB inherits classes B and C which inherit class A
	- This causes a compiler error saying CB::printName is ambiguous
- Classes D and F inherit public virtual A and class DF can call DF::printName without error

# Interface Classes
- Interface classes are not allowed to have implementation or state
	- Because they only contain pure virtual functions and a virtual destructor
	- if your objects are going to be unrelated then an interface would be better
- Abstract classes however can retain both state and implementation
	- they can contain both virtual and non-virtual functions as well as pure virtual functions
	- Abstract classes are best used when the derived objects will be closely related
```cpp
template<class type>
class Shape 
{
	virtual ~Shape();
	//pure virtual function
	virtual type area() = 0;
	virtual type perimeter() = 0;
};

# Mixin Classes
Mixins are used to combine independent classes that share the same base class - multiple inheritance
```cpp
#include <iostream>

using namespace std;

class A {
public:
	void printName() {
		cout << "A\n";
	}
};

template<class classType>
class B : public classType {
public:
	void printName() {
		cout << "class B calling A::printName() \n";
		classType::printName();
	}
};

template<class classType>
class C : public classType {
public:
	void printName() {
		cout << "class C calling B::printName() \n";
		classType::printName();
	}
};


int main(int argc,char* argv[]) {

	//Create mixin class.
	C<B<A>> myMixin;

	myMixin.printName();

	return 0;
}
```
