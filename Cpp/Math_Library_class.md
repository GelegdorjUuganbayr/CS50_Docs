# Class
C++ applications typically consist of multiple files. In order to avoid the duplication of code, header file and the #include preprocessor directive are used.

In C++, the common practice is to create your classes as two separate files:
- Header file
  - .h extension on the filename
  - Contain the declarations found in the class file.
  - Declarations include function prototypes and class constructors.
  - It is a concise method of describing what the class is intended to do.
  -  It also provides us with a mechanism to help reduce coding bugs by having the compiler catch omissions and misuses of the class and its components.
- Implementation file
  - .cpp or .c extension on the filename
  - The actual implementation of the code that performs the processing.
  
### Math.h
```cpp
#pragma once

// Math class definition
static class Math
{
  public:
  
  // given base and exponent, calculate value
  static int Math::pow(int base, int exp);
};
```

**\#pragma once**
- This tells the compiler to only include this header once, regardless of how many times it has been imported in the program.

**static class Math**
- A declared class as static, it is an indicator that we do not have to instantiate the class to use it in our program.
- Utility class
```cpp
// Without static
Math math = new Math();
math.pow(2, 8);

// With static
Math::pow(2, 8);
```

**static int Math::pow(int base, int exp)**
-  In order to call the function from a static class, the method must also be static.

### Math.cpp
```cpp
#include "Math.h"

int Math::pow(int base, int exp)
{
    int result = 1;

    for (int i = 0; i < exp; i++)
    {
        result = result * base;
    }

    return result;
}
```

**#include "Math.h"**
-  The compiler needs to know what functions are part of this class

**int Math::pow(int base, int exp)**
- Instead of just the function name, we are using Math::pow as the function name. This is using the concept of a scope resolution operator (::)
- It is required to call static members of the class.  

### main.cpp
```cpp
#include "Math.h"
#include <iostream>

using namespace std;

int main()
{
    int result = Math::pow(2, 10);

    cout << result << endl;

    return 0;
}
```

**int result = Math::pow(2, 10)**
- Note the use of the scope resolution operator again (::) and that we did not create an instance of the Math class but simply called the function directly on the class itself.
