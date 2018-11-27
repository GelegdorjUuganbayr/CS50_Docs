# Compiler on Linux Command Line
The original GNU C Compiler (GCC) is developed by Richard Stallman, the founder of the GNU Project. Richard Stallman founded the GNU project in 1984 to create a complete Unix-like operating system as free software, to promote freedom and cooperation among computer users and programmers.


- GCC, formerly for "GNU C Compiler", has grown over times to support many languages such as:
  - C (gcc)
  - C++ (g++)
  - Objective-C
  - Objective-C++
  - Java (gcj)
  - Fortran (gfortran)
  - Ada (gnat)
  - Go (gccgo)
  - OpenMP
  - Cilk Plus
  - OpenAcc.
- It is now referred to as "GNU Compiler Collection".
- The mother site for GCC is http://gcc.gnu.org/. The current version is GCC 7.3, released on 2018-01-25.

## GCC version
- GCC version 1 (1987): Initial version that support C.
- GCC version 2 (1992): supports C++.
- GCC version 3 (2001): incorporating ECGS (Experimental GNU Compiler System), with improve optimization.
- GCC version 4 (2005):
- GCC version 5 (2015):
- GCC Version 6 (2016):
- GCC Version 7 (2017):

## C++ standard support
The default mode is C++98 for GCC versions prior to 6.1, and C++14 for GCC 6.1 and above. You can use command-line flag -std to explicitly specify the C++ standard. For example,
- std=c++98, or -std=gnu++98 (C++98 with GNU extensions)
- std=c++11, or -std=gnu++11 (C++11 with GNU extensions)
- std=c++14, or -std=gnu++14 (C++14 with GNU extensions), default mode for GCC 6.1 and above.
- std=c++17, or -std=gnu++17 (C++17 with GNU extensions), experimental.
- std=c++2a, or -std=gnu++2a (C++2a with GNU extensions), experimental.

## gcc info
### gcc --version
```
$ gcc --version

gcc (GCC) 6.4.0
```
### gcc -v
```
$ gcc -v

Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-pc-cygwin/6.4.0/lto-wrapper.exe
Target: x86_64-pc-cygwin
Configured with: ......
Thread model: posix
gcc version 6.4.0 (GCC)
```
### help
```
$ gcc --help
$ man gcc
$ man g++
$ man gcc | col -b > gcc.txt
```

# Compile
## Compile C
The GNU C and C++ compiler are called gcc and g++, respectively.
### hello.c
```c
#include <stdio.h>
 
int main() {
    printf("Hello, world!\n");
    return 0;
}
```

### terminal - default compile
```
$ gcc hello.c
$ chmod a+x a.out
$ ./a.out
```
- The default output executable is called "a.out" (Unixes and Mac OS X)
- In Bash shell, the default PATH does not include the current working directory. Hence, you need to include the current path (./) in the command.
- You also need to include the file extension, if any, i.e., "./a.out".
  - In Unixes, the output file could be "a.out".
- You need to assign executable file-mode (x) to the executable file "a.out", via command "chmod a+x filename" 
  - add executable file-mode "+x" to all users "a+x"

### terminal - compile specifying the output filename
```
$ gcc -o hello hello.c
$ chmod a+x hello
$ ./hello
```
- In Unixes, we typically omit the .exe file extension, and simply name the output executable as hello (via command "gcc -o hello hello.c").
- You need to assign executable file mode via command "chmod a+x hello".

---
## Compile C++
### hello.cpp
```cpp
#include <iostream>
using namespace std;
 
int main() {
   cout << "Hello, world!" << endl;
   return 0;
}
```

### terminal
```
$ g++ -o hello hello.cpp
$ chmod a+x hello
$ ./hello
```




