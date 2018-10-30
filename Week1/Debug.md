# Debug
> Debug method for the **CS50 IDE**.
## help50
```
$ help50 make [file_name]
```
This will allow you to find the compile error.

## eprintf
**[eprintf.c]**
```cpp
#import <cs50.h>
#import <stdio.h>

int main(void)
{
  printf("Hello, world\n");
  eprintf("Checking error\n");
}
```
**[terminal]**
```
$ ./a.out
Hello, world
eprintf.c.7: Checking error
```
This will show where the print is to debug the code.

## debug50
Set the break point first, then run until the break point.
```
$ debug50 ./a.out
```
Once you type above, the program will run until break point and freeze.\
You can resume, step over, step into, or step out.

## GDB
To kick off with GDB
```
$ gdb [program name]
```
This will pull up the GDB environment. From this point, the next two major commands you will likely use are:
```
b [function name/line number]
```
Make it so that once your program begins, it will run uninterupted until it encounters the function with that name or hits that ine number, at which point the program will pause execution and await further input.
```
r [command-line argument]
```
Runs the program with the command line arguments provided if any.

| Commend      | Description                                        |
|--------------|-----------------------------------------------------------------------|
| n            | Step forward one block of code                                        |
| s            | Step forward one line of code                                         |
| p [variable] | Prints out the value of the variable given                            |
| info local   | Prints out the values of all local variables                          |
| bt           | Shows what series of function calls have led you to the current point |
| q            | Quits GDB                                                             |

