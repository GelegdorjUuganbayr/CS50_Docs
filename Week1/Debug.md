# Debug
> Debug method for the **CS50 IDE**.
### help50
```
$ help50 make [file_name]
```
This will allow you to find the compile error.

### eprintf
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
