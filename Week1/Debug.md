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
