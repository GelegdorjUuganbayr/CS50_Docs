# Memory Allocation
### When it needs to allocate memory from a custom memory pool instead of the free store.
- Where a bad_alloc exception is thrown due to memory exhaustion
- Log to file but need to use memory we reserved at the start of the program
  - Garbage collector
  - Video buffer

### Replace the allocator in an entire code base
- The Loki library which also implements its own small object allocator
  - These small objects use polymorphic behaviour, so they need to live on the heap, not the stack
- Some implementations of the new operator have bad performance
  - speed of allocation
  - using too much memory in the allocation process/free allocator

```cpp
#include <new>
#include <iostream>

using namespace std;

//Allocator class
class MyNewDeleteAllocator {
public:
    MyNewDeleteAllocator() {}
    ~MyNewDeleteAllocator() {}
    static void* operator new (size_t size); 
    static void operator delete (void *p);
};
void* MyNewDeleteAllocator::operator new (size_t size){
    void *p;
    p = malloc(size);
    if (p == NULL) {
        //Throw bad_alloc.
        std::bad_alloc exception;
        throw exception;
    }
    cout << "MyNewDeleteAllocator::operator new called with size_t " << size << endl;
    return p;
}
void MyNewDeleteAllocator::operator delete (void *p){
    cout << "MyNewDeleteAllocator::operator delete called. " << endl;
    delete[] p;
}

int main()
{
    MyNewDeleteAllocator *p = new MyNewDeleteAllocator; //Create MyNewDeleteAllocator object.
    delete p; //Delete MyNewDeleteAllocator object.

    return 0;
}
```
- It is possible to override them globally however this is not recommended
  - if your application uses other libraries, it would cause those included libraries to use your overridden new and delete as well.
- Throw a custom exception in the new operator
  - The memory allocation fails, this would allow you to create the exception on some reserved memory
  - If the application suffers memory exhaustion, the error will still be created/logged.
  
# Caching
- Caching is the ability to retrieve often used data quickly.
  - The data needs to be stored somewhere for it to be retrieved.
- The std::vector is most often used
  - It is guaranteed to be stored in contiguous memory which allows the linear search to be efficiently performed
- Most caching solutions involve a Least recently used algorithm
  - Remove least recently used data from the container so the most recently used is near the front of the container which supports fast search times
- The register keyword can be used to tell the compiler that:
  - It will be accessed a lot 
  - To keep the variable in a machine register
```cpp
for(register int i = 0; i < 9999999; i++){}
```

### alignas
- it allows us to align a variable to a multiple number of bytes

### alignof
- it gives us the required alignment of a type in bytes.

```cpp
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main(){

    std::vector<int> myvec;
    std::vector<int> myvec2;
    clock_t clock_time;

    clock_time = clock();
    for(int i = 0; i < 9999999; i++) {
        myvec.push_back(999);
    }
    clock_time = clock() - clock_time;

    printf("Loop without index in register took %f seconds \n", ((float)clock_time/CLOCKS_PER_SEC));
    //clear vector.
    myvec.clear();

    //start timer
    clock_time = clock();
    for (register int t = 0; t < 9999999; t++) {
        myvec2.push_back(999);
    }
    clock_time = clock() - clock_time;
    //end timer.

    //clear vector.
    myvec2.clear();


    printf("Loop with index in register took %f seconds \n", ((float)clock_time / CLOCKS_PER_SEC));

    //c++11 alignment keywords
    alignas(16) int a[4];
    alignas(1024) int b[4];

    //Output padded results
    printf("%p\n", a);
    printf("%p\n", b);

    if (_alignof(a) == 16) {
        cout << "int b aligned to 16 bytes" << endl;
    }

    if(_alignof(b) == 1024) {
        cout << "int b aligned to 1024 bytes" << endl;
    }

    return 0;
}
```

# Control timing of construction and destruction
You can also use placement new to re allocate an object and call the deconstructor explicitly. 

```cpp
#include <iostream>

using namespace std;

class MyClass {

public:
    MyClass() {
        cout << "MyClass constructor called." << endl;
    }

    ~MyClass() {
        cout << "MyClass deconstructor called." << endl;
    }
    std::string msg = "Hello World!!";
};


int main() {

    MyClass* mcptr;
    mcptr = new MyClass();
    delete mcptr;

    new(mcptr) MyClass();
    mcptr->~MyClass();

    return 0;
}
```
