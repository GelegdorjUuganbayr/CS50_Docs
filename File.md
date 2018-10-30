# File Pointers
- The file manipulation functions are in <stdio.h>
- All of them accept FILE* as one of their parameters, which is used to get a file pointer in the first place. (except fopen())

### Most common file input/output (I/O) functions.
```
fopen()
fclose()
fgetc()
fputc()
fread()
fwrite()
```

### fopen()
- Opens a file and returns a file pointer to it.
- Always check the return value to make sure you don't get back NULL.

```cpp
File* ptr = fopen([file_name], [operation]);
File* ptr1 = fopen("file1.txt","r"); // read a file
File* ptr2 = fopen("file2.txt","w"); // write a file (overwrite)
File* ptr3 = fopen("file3.txt","a"); // append a file (without losing contents)
```

### fclose()
- closes the file pointed to by the given file pointer

```cpp
fclose([file_pointer]);
fclose(ptr1);
```

### fgetc()
- Reads and returns the next character from the file pointed to
- Note: The operation of the file pointer passed in as a parameter must be "r" for read, or error occurs.
- The aibility to get signle characters from files, fi wrapped in a loop, means we could read all the characters from a file and print them to the screen, one-by-one, essentially.

```cpp
char ch = fgetc([file_pointer]);
char ch = fgetc(ptr1);

char ch1;
while((ch = fgetc(ptr)) != EOF)
  printf("%c", ch);
```

### fputc()
- Writes or appends the specified character to the pointed-to file.
- Note: The operation of the file pointer passed in as a parameter must be "w" for write or "a" for append.

```cpp
fputc([character],[file_pointer]);
fputc('A', ptr2);

// Copy the contents of the file and duplicate it
char ch;
while((ch = fgetc(ptr)) != EOF)
  fputc(ch, ptr2);
```

### fread()
- Reads <qty> units of size <size> from the file pointed to and stores them in memory in a buffer (usually an array) pointed to by <buffer>.
- Note: The operation of the file pointer passed in as a parameter must be "r" for read.

```cpp
fread([buffer],[size],[qty],[file_pointer]);

int arr[10];
fread(arr, sizeof(int), 10, ptr); // read [sizeof(int) * 10] from the file and store it in array [arr]

double* arr2 = malloc(sizeof(double) * 80);
fread(arr2, sizeof(double), 80, ptr);

char c;
fread(&c, sizeof(char), 1, ptr);  // Note address of variable is used
```

### fwrite()
- Writes <qty> units of size <size> to the file pointed to by reading them from a buffer (usually array) pointed to by <buffer>
- Note: The operation of the file pointer passed in as a parameter must be "w" for write or "a" for append.

```cpp
fwrite([buffer],[size],[qty],[file_pointer]);

int arr[3] = {1, 2, 3};
fwrite(arr, sizeof(int), 3, ptr);
```
