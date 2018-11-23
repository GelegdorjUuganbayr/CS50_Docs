# Staindard container classes
A container class is used to hold and organize objects of other classes
- This allows us to apply generic algorithms to the containers do perform operations such as sorting
- Containers are available in two designs
  - Composition which store copies of the objects and will call the constructors and de-constructors of those objects.
  - Aggregations which means they store pointers or references to other objects and thus are not responsible for their creation and destruction.

## Sequence containers
elements are accessed sequentially by position
- vector
- list
- deque
- array
- forward_list

## Associative containers
Provide efficient access to elements by key.\
Map and set keys must be unique.
- set: the value is the key
- multiset: the value is the key
- map:  key - value pairs
- multimap: key - value pairs

```cpp
//Max values.
cout << "myvector max value is " << *max_element(myvector.begin(), myvector.end()) << endl;

//Sorting
sort(myvector.begin(),myvector.end());

//Reverse containers
reverse(myvector.begin(), myvector.end());

//Partial sort
partial_sort(myvector.begin(), myvector.begin()+5,myvector.end());

```

# non-type template parameters
Non type integral arguments are matched to the template argument as long as the sign and value match the template type

# Template adpaters
Template adapters allow the implementation of the adapter design pattern.
- This design pattern is used when you want to implement an interface to reuse existing code that does not provide the required interface.
```cpp
class Cat {
public:
	void makeCatMeow() {
		cout << catnoise.c_str() << endl;
	}
private:
	string catnoise = "meow meow";
};  

class AnimalInterface {
public:
	//Destructor
	virtual ~AnimalInterface() {}
	//Pure virtual execute function has to be implemented by derived classes.
	virtual void execute() = 0;
};

template <class T>
class AnimalAdapter : public AnimalInterface {
public:
	//Constructor
	AnimalAdapter(T *o, void(T:: *m)()) {
		animalObject = o;
		animalfunction = m;
	}
	//Deconstructor.
	~AnimalAdapter() {
		delete animalObject;
	}
	//Implement AnimalInterface pure virtual function.
	void execute() {
		(animalObject->*animalfunction)();
	}
private:
	//Members to hold object and function pointers
	T *animalObject;
	void(T:: *animalfunction)();
};    
```
This allows us to use the AnimalAdapter class with multiple different animal class types and print out their animal sounds.

## Default template parameters
Default template arguments can have value or type defaults
```cpp
#include <iostream>

using namespace std;

template<typename A=int, typename B=double , int anint = 5>
void printParams(A ain,B bin) {
	cout << "Arguments are A is type " << typeid(ain).name() << " with value " << ain << " B type is " << typeid(bin).name() << " with value " << bin << " anint is " << anint << endl;
}

template<class C, typename A = int, typename B = double, int anint = 5 >
class myClass {
public:
	myClass(C myc, A ain, B adouble) {
		cout << "myClass constructor parameters myc is type " << typeid(myc).name() << " with value " << myc << " anint is " << ain << " adouble is " << adouble << " anint is " << anint << endl;
	}
};
```

## Specialissing Template
template class or function that is used with many different types, but function or class to make use of a particular type more efficiently
- To declare a template specialization we still use the template keyword and angle brackets <> but leave out the parameters like so.
```cpp
template<typename T>
void printFunction(T arg) {
	cout << "printFunction arg is type " << typeid(arg).name() << " with value " << arg << endl;
}

// Then we can specialize this for integer values like so.
template<>
void printFunction(int intarg) {
	cout << "printFunction specialization with int arg only called with type " << typeid(intarg).name() << " with value " << intarg << endl;
}
```

### Recursion with specialising Template
```cpp
template<int N>
void printCountUp() {
	printCountUp<N-1>();
	cout << N << "\n";
}

// Base case
template<>
void printCountUp<0>() {
	 cout << 0 << "\n";
} 
```

### Partial template specialization
```cpp
template<typename T,int size>
void printParamTypes(T myt) {
	cout << "printParamTypes types are " << typeid(myt).name() << " and size " << typeid(size).name() << " with value " << size << endl;
}

## Trait Classes
A type specific implementation of a function that takes advantage of the machines hardware to compute something much faster than generic c++ code
```cpp
template<class T> struct my_traits;

template<>
struct my_traits<int> {
	enum { TypeId = MYNATIVE_INTEGER};
	typedef mynative_integer MyNativeType;
	static void Convert(MyNativeType from, int& to){
		cout << "MyNativeIntegerType Convert \n";
		to = static_cast<int>(from);
	}
};

template<>
struct my_traits<double> {
	enum { TypeId = MYNATIVE_DOUBLE };
	typedef mynative_double MyNativeType;
	static void Convert(MyNativeType from, double& to) {
		cout << "MyNativeDoubleType Convert \n";
		to = static_cast<double>(from);
	}
};
```


template<int size>
void printParamTypes(char c) {
	cout << "printParamTypes partial specialization types are " << typeid(c).name() << " with value " << c << " and size " << typeid(size).name() << " with value " << size << endl;
}
```
