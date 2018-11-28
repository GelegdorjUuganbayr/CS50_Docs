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

# Compile Link
A few commonly-used GCC compiler options
```
$ g++ -Wall -g -o Hello.exe Hello.cpp
```
- o: specifies the output executable filename.
- Wall: prints "all" Warning messages.
- g: generates additional symbolic debuggging information for use with gdb debugger.

## Sparate step for compile and link
```
// Compile-only with -c option
$ g++ -c -Wall -g Hello.cpp

// Link object file(s) into an executable
$ g++ -g -o Hello.exe Hello.o
```
- c: Compile into object file "Hello.o".
  - By default, the object file has the same name as the source file with extension of ".o" (there is no need to specify -o option)
  - No linking with other object files or libraries.
- Linking is performed when the input file are object files ".o" (instead of source file ".cpp" or ".c"). 
  - GCC uses a separate linker program (called ld.exe) to perform the linking.
  
## Compile and link Multiple source file
Suppose that your program has two source files: file1.cpp, file2.cpp. You could compile all of them in a single command:
```
$ g++ -o myprog.exe file1.cpp file2.cpp 
```
However, we usually compile each of the source files separately into object file, and link them together in the later stage. In this case, changes in one file does not require re-compilation of the other files.
```
$ g++ -c file1.cpp
$ g++ -c file2.cpp
$ g++ -o myprog.exe file1.o file2.o
```

# Environment Variables
GCC uses the following environment variables:

- PATH: For searching the executables and run-time shared libraries (.dll, .so).
- CPATH: For searching the include-paths for headers. It is searched after paths specified in -I<dir> options. C_INCLUDE_PATH and CPLUS_INCLUDE_PATH can be used to specify C and C++ headers if the particular language was indicated in pre-processing.
- LIBRARY_PATH: For searching library-paths for link libraries. It is searched after paths specified in -L<dir> options.

# Makefile

### hello.c
```cpp
#include <stdio.h>
 
int main() {
    printf("Hello, world!\n");
    return 0;
}
```

### makefile
```
target: pre-req-1 pre-req-2 ...
	command
```

### makefile - EXAMPLE
```
all: hello.exe

hello.exe: hello.o
	 gcc -o hello.exe hello.o

hello.o: hello.c
	 gcc -c hello.c
     
clean:
	 rm hello.o hello.exe
```
Create the following file named "makefile" (without any file extension), which contains rules to build the executable, and save in the same directory as the source file. Use "tab" to indent the command (NOT spaces).
- The rule "all" has a pre-requisite "hello.exe"
  - make cannot find the file "hello.exe", so it looks for a rule to create it
- The rule "hello.exe" has a pre-requisite "hello.o"
  - Again, it does not exist, so make looks for a rule to create it
- The rule "hello.o" has a pre-requisite "hello.c"
  - make checks that "hello.c" exists and it is newer than the target (which does not exist)
  - It runs the command "gcc -c hello.c". The rule "hello.exe"
  - then run its command "gcc -o hello.exe hello.o"
  - Finally, the rule "all" does nothing

### Run the "make" utility
```
$ make
```
- **make**
  - gcc -c hello.c
  - gcc -o hello.exe hello.o

### Exists pre-requisite (old)
```
$ make
make: Nothing to be done for `all'.
```
- Importantly, if the pre-requisite is not newer than than target, the command will not be run. In other words, the command will be run only if the target is out-dated compared with its pre-requisite. For example, if we re-run the make command:

### clean
```
$ make clean
 
$ make
```
- You can also specify the target to be made in the make command. For example, the target "clean" removes the "hello.o" and "hello.exe". You can then run the make without target, which is the same as "make all".
- make clean
  - rm hello.o hello.exe
- make
  - gcc -c hello.c
  - gcc -o hello.exe hello.o

## make rule
- If the command is not preceded by a tab, you get an error message "makefile:4: *** missing separator. Stop."
- If there is no makefile in the current directory, you get an error message "make: *** No targets specified and no makefile found. Stop."
- The makefile can be named "makefile", "Makefile" or "GNUMakefile", without file extension.
- A comment begins with a # and lasts till the end of the line.
- Long line can be broken and continued in several lines via a back-slash (\).

### Syntax of rules
```
target1 [target2 ...]: [pre-req-1 pre-req-2 ...]
	[command1
	 command2
	 ......]
   
clean:
	 rm hello.o hello.exe
```
- The rules are usually organized in such as way the more general rules come first. The overall rule is often name "all", which is the default target for make.

### phony Targets (Artificial Targets)
A target that does not represent a file is called a phony target.
- For example, the "clean" in the above example, which is just a label for a command
- Phony target is always out-of-date and its command will be run
  - If the target is a file, it will be checked against its pre-requisite for out-of-date-ness
- The standard phony targets
  - all
  - clean
  - install.

### variables
- A variable begins with a $
- A variable is enclosed within parentheses (...) or braces {...}
- Single character variables do not need the parentheses
  - e.g. $(CC), $(CC_FLAGS), $@, $^

### Automatic variables
Automatic variables are set by make after a rule is matched. There include:
- $@: the target filename.
- $*: the target filename without the file extension.
- $<: the first prerequisite filename.
- $^: the filenames of all the prerequisites, separated by spaces, discard duplicates.
- $+: similar to $^, but includes duplicates.
- $?: the names of all prerequisites that are newer than the target, separated by spaces.
```
all: hello.exe

hello.exe: hello.o
	gcc -o $@ $<

hello.o: hello.c
	gcc -c $<
     
clean:
	rm hello.o hello.exe
```
- **gcc -o $@ $<**
  - gcc -o hello.exe hello.o
- **gcc -c $<**
  - gcc -c hello.c

## Virtual Path
You can use VPATH (uppercase) to specify the directory to search for dependencies and target files.
```make
# Search for dependencies and targets from "src" and "include" directories
# The directories are separated by space
VPATH = src include
```
You can also use vpath (lowercase) to be more precise about the file type and its search directory.
```make
# Search for .c files in "src" directory; .h files in "include" directory
# The pattern matching character '%' matches filename without the extension
vpath %.c src
vpath %.h include
```

## Pattern Rules
A pattern rule, which uses pattern matching character '%' as the filename, can be applied to create a target, if there is no explicit rule.
```make
# Applicable for create .o object file.
# '%' matches filename.
# $< is the first pre-requisite
# $(COMPILE.c) consists of compiler name and compiler options
# $(OUTPUT_OPTIONS) could be -o $@
%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<
 
# Applicable for create executable (without extension) from object .o object file
# $^ matches all the pre-requisites (no duplicates)
%: %.o
$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@
```

# Example
```make
# A sample Makefile
# This Makefile demonstrates and explains 
# Make Macros, Macro Expansions,
# Rules, Targets, Dependencies, Commands, Goals
# Artificial Targets, Pattern Rule, Dependency Rule.

# Comments start with a # and go to the end of the line.

# Here is a simple Make Macro.
LINK_TARGET = test_me.exe

# Here is a Make Macro that uses the backslash to extend to multiple lines.
OBJS =  \
 Test1.o \
 Test2.o \
 Main.o

# Here is a Make Macro defined by two Macro Expansions.
# A Macro Expansion may be treated as a textual replacement of the Make Macro.
# Macro Expansions are introduced with $ and enclosed in (parentheses).
REBUILDABLES = $(OBJS) $(LINK_TARGET)

# Here is a simple Rule (used for "cleaning" your build environment).
# It has a Target named "clean" (left of the colon ":" on the first line),
# no Dependencies (right of the colon),
# and two Commands (indented by tabs on the lines that follow).
# The space before the colon is not required but added here for clarity.
clean : 
  rm -f $(REBUILDABLES)
  echo Clean done

# There are two standard Targets your Makefile should probably have:
# "all" and "clean", because they are often command-line Goals.
# Also, these are both typically Artificial Targets, because they don't typically
# correspond to real files named "all" or "clean".  

# The rule for "all" is used to incrementally build your system.
# It does this by expressing a dependency on the results of that system,
# which in turn have their own rules and dependencies.
all : $(LINK_TARGET)
  echo All done

# There is no required order to the list of rules as they appear in the Makefile.
# Make will build its own dependency tree and only execute each rule only once
# its dependencies' rules have been executed successfully.

# Here is a Rule that uses some built-in Make Macros in its command:
# $@ expands to the rule's target, in this case "test_me.exe".
# $^ expands to the rule's dependencies, in this case the three files
# main.o, test1.o, and  test2.o.
$(LINK_TARGET) : $(OBJS)
  g++ -g -o $@ $^

# Here is a Pattern Rule, often used for compile-line.
# It says how to create a file with a .o suffix, given a file with a .cpp suffix.
# The rule's command uses some built-in Make Macros:
# $@ for the pattern-matched target
# $< for the pattern-matched dependency
%.o : %.cpp
  g++ -g -o $@ -c $<

# These are Dependency Rules, which are rules without any command.
# Dependency Rules indicate that if any file to the right of the colon changes,
# the target to the left of the colon should be considered out-of-date.
# The commands for making an out-of-date target up-to-date may be found elsewhere
# (in this case, by the Pattern Rule above).
# Dependency Rules are often used to capture header file dependencies.
Main.o : Main.h Test1.h Test2.h
Test1.o : Test1.h Test2.h
Test2.o : Test2.h

# Alternatively to manually capturing dependencies, several automated
# dependency generators exist.  Here is one possibility (commented out)...
# %.dep : %.cpp
#   g++ -M $(FLAGS) $< > $@
# include $(OBJS:.o=.dep)
```
