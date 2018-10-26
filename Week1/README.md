# CS50_Docs
How human language is translated to what a computer can understand (binary)
Source code -> Compiler -> Machine code (Binary)

File name should be consist of lower case with underline instead of space (by convention)
### hello.c
```c
#include <stdio.h>

int main (void)
{
  printf("Hello world");
}
```

To compile the source code, we need to compile through the terminal. Once compile is done, file [a.out] is generated.
```
$ clang hello.c
```

To run the program, we need to type below:
```
$ ./a.out
```
.(dot) means look in current directory, and /(slash) mean seperater - seperate folder name, and a.out is the name of program./
To change the output name, put [-o] after compiler, and put name you want to give for the output file.
```
clang -o hello hello.c
```

