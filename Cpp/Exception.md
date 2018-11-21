# Exceptions Handling

## Basic Exception Handling
### try-catch exeption handling
```cpp
#include <iostream>
#include <string>

int main() {
    try {
        throw 6;
    }
    catch(int e) {
        std::cout << "Int exception thrown " << std::to_string(e) << std::endl;
    }
}
```

## Standard exception class hierarchy
Exception base class that can be derived and overridden
  - what
  - ~exception virtual function

This allows 
- return a custom error message string
- destructor allows to free any memory allocated on the heap with the **new**

```cpp
#include <iostream>
#include <exception>

using namespace std;

class derivedexception: public exception
{
    virtual const char* what() const throw() {
        return "My derived exception";
    }
} myderivedexception;

int main ()
{
    try {
        throw myderivedexception;
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }
}
```
- class derivedexception: public exception
  - Accessing the base class exception's public members
- virtual const char* what() const throw()
  - override base class function what()
  - return const char* c-string "My derived exception"

### exception base class
All of below derive from std::exception, it can be caught by the std::exception type

```cpp
std::bad_alloc  //thrown by new
std::bad_cast   //thrown by dynamic_cast
std::bad_typeid  //thrown by typeid
std::bad_exception
std::logic_error  //thrown by reading the code
std::runtime_error  //thrown when not detecable by code analisys
std::bad_function_call  //c++11
std::bad_weak_ptr   //c++11
```

### std::logic_failure
```cpp
std::domain_error
std::invalid_argument
std::length_error
std::out_of_range
std::future_error  //c++11
```

### std::runtime_error
```cpp
std::overflow_error
std::range_error
std::underflow_error
std::system_error  //c++11
```

### std::bad_alloc
```cpp
std::bad_array_new_length
```

### std::system_error
```cpp
std::ios_base::failure
```

# Uncaught exceptions
ellipsis (...)
- this exception handler will catch any exception type that is thrown in its associated try-block.
- This can be used as the default case of chained exception handlers

### Chained exception handler
```cpp
try {
    throw 20;
}
catch (int exc) { cout << "int exception." << endl; }
catch (double exc) { cout << "double exception." << endl; }
catch (...) { cout << "All other exception types." << endl; }
  // output: int exception.
try {
    throw 20.0;
}
catch (int exc) { cout << "int exception." << endl; }
catch (double exc) { cout << "double exception." << endl; }
catch (...) { cout << "All other exception types." << endl; }
  // output: double exception.
try {
    throw true;
}
catch (int exc) { cout << "int exception." << endl; }
catch (double exc) { cout << "double exception." << endl;}
catch (...) { cout << "All other exception types." << endl; }
  // output: All other exception types.
```

### forward exceptions to the parent try-block using the throw keyword
```cpp
try {
    try {
        //Do something here that causes an exception
        throw 10;
    }
    catch (int numb) {
        cout << "Caught int exception." << endl;
        throw;
    }
}
catch (...) {
    cout << "An error occurred." << endl; 
}
```

- If there's no associated exception handler to catch it, an exception is uncaught.
  - A call to terminate() is done automatically
  - Any subsequent call to termination function including object destructor's functions doesn't happen
- Problematic for RAII (Resource acquisition is initialization)
  - Destructor throws an exception -> whole program will exit.
- When exception occurs, variables between the throw and catch are destroyed.

### One missing catch
```cpp
throwexception::throwexception(void) {
    cout << "throwexception object constructed" << endl;
    //Constructor
}

throwexception::~throwexception(void) {
    //Destructor
    cout << "throwexception destructor called." << endl;
    throw 9;
}

int main() {
    try {
        throwexception texc;
        cout << "Throwing exception will cause termination of program." << endl;
        throw 7;
    }
    catch (...) {
        //Catch exception
        cout << "Main Exception caught" << endl;
    }
} 
```
### output
```
throwexception destructor called.
```
- "Main Exception caught" is not printed because the destructor throw 9 again but there is no more catch for thrown exception.
- it is not considered good practice to throw exception in an objects destructor.

## Vector Exception handling
- Update two vectors using push_back and either:
  - update both vectors
  - update neither of them to keep them synchronised.
    - first vector update but the second vector update fails, roll back the update to the first vector.
```cpp
#include <iostream>
#include <vector>

using namespace std;

void updateVector(std::vector<std::string>& firstvector_, std::vector<std::string>& secondvector_, std::string newString) {
    firstvector_.push_back(newString);
    try {
        secondvector_.push_back(newString);
    }
    catch (...) {
        firstvector_.pop_back();
        cout << "second vector update failed." << endl;
    }
}

// wrong approach
void updateVector2(std::vector<std::string>& firstvector_, std::vector<std::string>& secondvector_, std::string newString) {
    firstvector_.push_back(newString);
    try {
        std::bad_alloc excep;
        throw excep;
        secondvector_.push_back(newString);
    }
    catch (...) {
        firstvector_.pop_back();
        cout << "second vector update failed." << endl;
    }
}
```
- if the first vector fails to update then the second vector is never tried
- if the second vector fails to update then the last item added to the first vector is removed and the exception passed up
- updateVector2 function throws an exception before updating the second vector
  -  the vector sizes being unchanged even though the first vector had already been updated

### Generic multi-vector update exception handling
```cpp
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<class TContainer>
class VecScopeGuard {
private:
    bool engaged_;
    TContainer* vecptr_;
public:
    VecScopeGuard(TContainer* vecptr)
        : engaged_(true),vecptr_(vecptr) { //Assign vecptr and set guard to true.
    }
    ~VecScopeGuard() { 
        if (engaged_) {
            //Remove last vector entry
            vecptr_->pop_back();
        }
    }
    void disengage() {
        engaged_ = false;
        //Vectors updated so release guard
    }
};

int main()
{
    vector<string> firstvector;
    vector<string> secondvector;
    string mystring("Hello world!");
    
    try {
        firstvector.push_back(mystring);
        VecScopeGuard<vector<string>> guard1(&firstvector);
        secondvector.push_back(mystring);
        VecScopeGuard<vector<string>> guard2(&secondvector);

        guard1.disengage();
        guard2.disengage();
    }
    catch(...) {
        cout << "Caught error." << endl;
    }
}
```
- destructor for VecScopeGuard which checks if it is engaged
  - if so calls the std::vector method pop_back()
- disengage function which sets the bool engaged_ to false to stop the pop_back() function being called in the destructor
- if the second vector throw an exception during the push_back() function, the exception handler will be invoked
  - the VecScopeGuard object around the first vector will move out of scope
  - it's destructor will be called
  - disengage() is sort of flag that push_back has been success so pop_back doesn't need to be implemented
  - this implementation is designed to only work with vectors as the VecScopeGuard destructor call the vector function pop_back()
  
## generic exception handling
Loki: http://loki-lib.sourceforge.net/
- ScopeGuard which allows you to roll back updates such as the above vectors in a more scalable solution
```cpp
void updateVector(std::vector<std::string>& firstvector,std::vector<std::string>& secondvector,std::string& newString){
    firstvector_.push_back(&newString);
    ScopeGuard guard = MakeObjGuard(&std::vector::pop_back,firstvector_);
    secondvector_.push_back(&newString);
    guard.Dismiss();
}
```
- The ScopeGuard guard object will call pop_back on the firstvector when it's scope is exited by the function updateVector unless we call guard.Dismiss() first.
- if the secondvector_.push_back fails the update to the first vector will be rolled back

# Exception Handling Strategies
You should always try to use the in built c++ throw and catch exception support.
- When an exception is encountered
  - The program should survive the exception and continue to process events
  - Or shut down gracefully
- Any resources that may have been opened or used when the exception is thrown by the program
  - need to be closed or freed by the exception handler
  - if it's not possible to continue all resources should be closed or freed on application shut down
- When an exception occurs the user needs to be notified via the user interface
- If the application uses third party library's such as data base drivers which can throw their own exception types
  - you should catch these exceptions and throw types your application understands
  - if you change databases then your application won’t break when different database driver throw exceptions
- Errors can be separated into 3 main areas
  - User errors such as passing invalid arguments to a command line application
    - It can be detected by validating parameters and then returning an error message
  - Third party errors such as a database or other service
    - It requires the developers to know about the responses from the underlying technology so as to decide what action to take, for instance a database request may fail and you might be able to retry the request against a mirrored database. Internal errors can be passively propagated up the call stack or intentionally passed
  - Internal errors in the application itself such as bugs
  
### old exception specifications
```cpp
void myfunction() throw();  //Does not throw an exception
void myfunction() throw(...);  //Throws an exception
void myfunction() throw(mytype);  //Throws exception of type mytype.  
```
### new exception specifications (c++11)
```cpp
void myfunction() noexcept;   //Throws an exception equal to noexcept(true)
void myfunction() noexcept(true/false);   //Throws an exception depending on boolean true/false
```

# Exception Safety
- try-catch
- RAII (resource acquisition is initialization)
  - It allows the ownership of a resource be given to a scoped object
- STL will provide exception safety unless as long as we provide it with operations which adhere to the library's basic requirements
- STL will not throw exceptions 
  - That leave memory leaks
  - Containers in an invalid state
- User defined operations need to do the same
- RAII guarantees such that the destructor will release all resources that the constructor has/tried to obtain
- Don't leave objects in an invalid state before throwing an exception
  - They can be accessed and destroyed and don't throw exception's from the destructor as this would lead to program termination
-  Representing resources as classes that obey the RAII policy is the best exception safe way of obtaining resources
  - The constructor succeeds to obtain them
  - It throws an exception and the objects destructor will be called which should release any resources acquired in the constructor
  
# Casting Exceptions

 
