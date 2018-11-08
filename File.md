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
fseek()
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

### fseek()
- The C library function fseek sets the file position of the stream to the given offset.

```cpp
int fseek(FILE *stream, long int offset, int whence)
```

- stream − This is the pointer to a FILE object that identifies the stream.
- offset − This is the number of bytes to offset from whence.
- whence − This is the position from where offset is added. It is specified by one of the following constants.
  - SEEK_SET: Beginning of file 
  - SEEK_CUR: Current position of the file pointer
  - SEEK_END: End of file
- Return Value - This function returns zero if successful, or else it returns a non-zero value.
### File Pointers functions

| Function  | Description                                                    |
|-----------|----------------------------------------------------------------|
| fgets()   | Reads a full string from a file                                |
| fputs()   | Writes a full string to a file                                 |
| fprintf() | Writes a formatted string to a file                            |
| fseek()   | Allows you rewind or fast-forward within a file                |
| ftell()   | Tells you at what (byte) position you are at within a file     |
| feof()    | Tells you whether you've read to the end of a file             |
| ferror()  | Indicates whether an error has occurred in working with a file |


# BMP file


| Header Name                | Bytes    |
|----------------------------|----------|
| BITMAPFILEHEADER           | 14 bytes |
| BITMAPINFOHEADER           | 40 bytes |

#### Smile face [8x8, 24-bit BMP]
- [000000] == **[Blue<00>,Green<00>,Red<00>]**
- value can be between 0 ~ 255 (00 ~ ff)

```
ffffff  ffffff  0000ff  0000ff  0000ff  0000ff  ffffff  ffffff
ffffff  0000ff  ffffff  ffffff  ffffff  ffffff  0000ff  ffffff
0000ff  ffffff  0000ff  ffffff  ffffff  0000ff  ffffff  0000ff
0000ff  ffffff  ffffff  ffffff  ffffff  ffffff  ffffff  0000ff
0000ff  ffffff  0000ff  ffffff  ffffff  0000ff  ffffff  0000ff
0000ff  ffffff  ffffff  0000ff  0000ff  ffffff  ffffff  0000ff
ffffff  0000ff  ffffff  ffffff  ffffff  ffffff  0000ff  ffffff
ffffff  ffffff  0000ff  0000ff  0000ff  0000ff  ffffff  ffffff
```

Should be able to see the value above with:
- Start with byte to 54: BITMAPFILEHEADER + BITMAPINFOHEADER
- Bytes per row to 24: 8px per row
- Bytes per column to 3: 24bits per pixel (BGL)

#### small square [3x3, 24-bit BMP]
Each scanline in small.bmp thus takes up 3 x 3 = 9 bytes, which is not a multiple of 4.\
And so the scanline is "padded" with as many zeroes as it takes to extend the scanline’s length to a multiple of 4.\
since (3px) × (3px) + (3 bytes of padding) = 12 bytes, 3 bytes' worth of zeroes are needed, which is indeed a multiple of 4.

```
00ff00 00ff00 00ff00 000000
00ff00 ffffff 00ff00 000000
00ff00 00ff00 00ff00 000000
```

## BMP header
#### [bmp.h]
- Size of BMP file will be 14bytes[BITMAPFILEHEADER] + 40bytes[BITMAPINFOHEADER] + 3bytes x (w x h)

```cpp
// BMP-related data types based on Microsoft's own

#include <stdint.h>

// aliases for C/C++ primitive data types
// https://msdn.microsoft.com/en-us/library/cc230309.aspx
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

// information about the type, size, and layout of a file
// https://msdn.microsoft.com/en-us/library/dd183374(v=vs.85).aspx
typedef struct
{
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} __attribute__((__packed__))
BITMAPFILEHEADER;

// information about the dimensions and color format
// https://msdn.microsoft.com/en-us/library/dd183376(v=vs.85).aspx
typedef struct
{
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} __attribute__((__packed__))
BITMAPINFOHEADER;

// relative intensities of red, green, and blue
// https://msdn.microsoft.com/en-us/library/dd162939(v=vs.85).aspx
typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;

```
