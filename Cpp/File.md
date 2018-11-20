# File Streams
The standard C++ library defines three stream-based classes that allow you to read and write data to/from files
- operators >> and operator <<
- These classes are defined in the <fstream> header file

| Function      	| Description                                                                                                                              	|
|---------------	|------------------------------------------------------------------------------------------------------------------------------------------	|
| std::ifstream 	| it inherits from std::istream, and allows you to read data from a file using the >> operator.                                            	|
| std::ofstream 	| it inherits from std::ostream, and allows you to write data to a file using the << operator.                                             	|
| std::fstream  	| it inherits from both std::istream and std::ostream, and allows you to read and write data to/from a file using the >> and << operators. 	|

## Open and Close files
```cpp
#include <fstream>

void openCloseFilesExplicitly()
{
    // Declare file stream objects (files aren't opened yet).
    std::ofstream ofile;
    std::ifstream ifile;
    std::fstream  iofile;

    // Open the files.
    ofile.open("file1.dat");    // Opens file1.dat for writing.
    ifile.open("file2.dat");    // Opens file2.dat for reading.
    iofile.open("file3.dat");   // Opens file3.dat for reading/writing.

    // Use the files...

    // Close the files.
    ofile.close();
    ifile.close();
    iofile.close();
}
```
open(): it takes a filename as a parameter and opens the specified file
close(): it closes the file when you're finished with it

### Open and Close files with file stream object's constructors and destructors
```cpp
#include <fstream>

void openCloseFilesImplicitly()
{
    // Declare file stream objects (files opened implicitly by constructors).
    std::ofstream ofile("file1.dat");
    std::ifstream ifile("file2.dat");
    std::fstream  iofile("file3.dat");

    // Use the files...

}   // Files closed implicitly by destructors.
```

## File Open Modes
When you open a file, you can optionally specify a mode parameter.

| Method                	| Description                                                                                                                                                             	|
|-----------------------	|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| std::ios_base::in     	| File will be opened for input operations. This is the default mode for std::ifstream objects.                                                                           	|
| std::ios_base::out    	| File will be opened for output operations. This is the default mode for std::ofstream objects.                                                                          	|
| std::ios_base::binary 	| File will be opened in binary mode. (i.e. no formatting will be applied to values when they are read or written.)                                                       	|
| std::ios_base::ate    	| Specifies the initial position for read/write operations is at the end of the file. The default initial position for read/write operations is at the start of the file. 	|
| std::ios_base::app    	| Specifies that all output operations will occur at the end of the file, thereby preserving the existing content in the file.                                            	|
| std::ios_base::trunc  	| This flag causes the existing content to be deleted and replaced with the new content that you write in your application.                                               	|

### Combine multi-open modes
```cpp
#include <fstream>

std::ofstream ofile1;
ofile1.open("file1.dat", std::ios_base::binary | std::ios_base::app);

std::ofstream ofile2("file2.dat", std::ios_base::binary | std::ios_base::app);
```
You can combine these flags together by using the bitwise OR operator (|)

### File open check
```cpp
#include <fstream>

std::fstream somefile("file3.dat");

if (somefile.is_open())
{
    // File opened OK, so use it…

    // Close the file when we're done.
    somefile.close();
}
else
{
    std::cerr << "Couldn't open file" << std::endl;
}  
```

## Reading and Writing Text Data
- The std::ifstream class inherits from std::istream.
  - You can use the >> operator to read data from a file
- The std::ofstream class inherits from std::ostream
  - You can use the << operator to write data to a file
- You can use methods such as std::getline() to read an entire line of text from a file stream object

### Writing Text Data
```cpp
#include <fstream>

std::ofstream ofile("file1.txt");
if (ofile.is_open())
{
    ofile << "Here is line 1." << std::endl;
    ofile << "Here is line 2." << std::endl;
    ofile << "Here is line 3." << std::endl;
    ofile.close();

    std::cout << "Finished writing text to file1.txt." << std::endl;
}
else
{
    std::cerr << "Couldn't open file1.txt for writing." << std::endl;
}
```
**file1.txt**
```
Here is line 1.
Here is line 2.
Here is line 3.
```

### Reading contents of file
```cpp
#include <fstream>

std::ifstream ifile("file1.txt");
if (ifile.is_open())
{
    std::string line;
    while (std::getline(ifile, line))
    {
        std::cout << line << std::endl;
    }
    ifile.close();        

    std::cout << "Finished reading text from file1.txt." << std::endl;
}
else
{
    std::cerr << "Couldn't open file1.txt for reading." << std::endl;
}
```

## Reading and Writing Formatted Text Data
- When writing data using the << operator, you must ensure values are separated from each other
  - e.g. by outputting a space between the values. 
- When reading data using the >> operator, you must know the order of tokens in the file.
  - e.g. if the next token is a double, then you must read it into a double variable.
  - If you try to read the value into the wrong type of variable, an error will occur.

eof()
- it tells you when you've reached the end of the file.

### Writing Formatted Text Data
```cpp
#include <fstream>

std::ofstream ofile("peopleFile.txt");
if (ofile.is_open())
{
    ofile << "John" << " " << 42 << " " << 1.67 << std::endl;
    ofile << "Jane" << " " << 41 << " " << 1.54 << std::endl;
    ofile << "Bill" << " " << 35 << " " << 1.82;
    ofile.close();
    std::cout << "Finished writing text to peopleFile.txt." << std::endl;
}
else
{
    std::cerr << "Couldn't open peopleFile.txt for writing." << std::endl;
}
```
 Note that we don't output a newline character after the final record
 - This is because we want the end-of-file marker to appear immediately after the final record, to indicate there's no more data in the file
 
 **output**
 ```
John[space]42[space]1.67[newline]
Jane[space]41[space]1.54[newline]
Bill[space]35[space]1.82[eof]
 ```
 
## Binary Data
Binary files are typically smaller than text files, and can be more efficient to read and write.\
These characteristics are particularly beneficial if you have a large amount of data to store.

- Open the file in binary mode. To do this, specify the std::ios::binary mode in the open() method or the file stream constructor.
- Call the read() or write() method to read or write binary data, respectively. Both of these methods take two parameters:
  - The address of the variable to read or write, expressed as a (char*) pointer.
  - The size of the value to read or write, in bytes. You can use the C++ sizeof operator to obtain this value.

 ```cpp
class tempStat
{
    public:
    // Data members.
    double minimum, maximum;
    static const size_t RECORD_SIZE = 2 * sizeof(double);
    
    // Constructor.
    tempStat(double min = 0.0, double max = 0.0)
        : minimum(min), maximum(max)
    {}

    // Helper method, to write a tempStat object to a file in binary format.
    void write(std::ostream & os, int index)
    {
        std::streampos pos(index * RECORD_SIZE):
        
        os.seekp(pos);
        std::cout << "About to write record at position " << os.tellp() << std::endl;
        
        os.write((char*)&minimum, sizeof(double));
        os.write((char*)&maximum, sizeof(double));
    }

    // Helper method, to read a tempStat object from a file in binary format.
    void read(std::istream & is, int index)
    {
        std::streampos pos(index * RECORD_SIZE);
        
        is.seekg(pos); // seek get pos
        std::cout << "About to read record at position " << is.tellg() << std::endl;
        
        is.read((char*)&minimum, sizeof(double));
        is.read((char*)&maximum, sizeof(double));
    }
};

// Operator overloading
std::istream& operator >> (std::istream& is, tempStat & ts)
{
    is >> ts.minimum >> ts.maximum;
    return is;
}
std::ostream& operator << (std::ostream & os, const tempStat & ts)
{
    os << ts.minimum << "," << ts.maximum << std::endl;
    return os;
}
```

### Write binary file
```cpp
std::ofstream ofile("tempStats.bin", std::ios_base::binary);
if (ofile.is_open())
{
    tempStat(-2.5, 7.5).write(ofile);
    tempStat(0, 9.9).write(ofile);
    tempStat(2.5, 11.0).write(ofile);
    tempStat(5.5, 14.5).write(ofile);
    tempStat(7.0, 17.7).write(ofile);
    tempStat(10.5, 23.7).write(ofile);
    tempStat(11.7, 29.5).write(ofile);
    tempStat(7.6, 22.9).write(ofile);
    tempStat(7.2, 21.5).write(ofile);
    tempStat(2.0, 16.0).write(ofile);
    tempStat(-4.7, 12.5).write(ofile);
    tempStat(-1.9, 8.5).write(ofile);

    ofile.close();

    std::cout << "Finished writing binary data to tempStats.bin." << std::endl;
}
else
{
    std::cerr << "Couldn't open tempStats.bin for writing." << std::endl;
}
```

### Read binary file
```cpp
std::ifstream ifile("tempStats.bin", std::ios_base::binary);
if (ifile.is_open())
{
    while (!ifile.eof())
    {
        tempStat ts;
        ts.read(ifile);

        if (ifile.gcount() == 0) 
        {
            break;  // If no bytes read, we're done.
        }

        std::cout << "Read temperature stats: " << ts << std::endl;
    }
    ifile.close();

    std::cout << "Finished reading binary data from tempStats.bin." << std::endl;
}
else
{
    std::cerr << "Couldn't open tempStats.bin for reading." << std::endl;
}
```

## Getting and Setting the Position in a Stream
istream and ifstream objects keep track of the current "get" position.
- tellg(): current get position
- seekg(): modify the current get position

ostream and ofstream objects keep track of the current "put" position
- tellp(): current put position
- seekp(): modify the current put position

The tellg() and tellp() methods return a std::streampos value
```cpp
std::istream& seekg (std::streampos pos);
std::ostream& seekp (std::streampos pos);
```
