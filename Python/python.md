# Python

### C
```C
#include <stdio.h>

int main()
{
  printf("hello, world\n");
  return 0;
}
```

### Python
```python
def main():
  print("hello, world)
  
if __name__ == "__main__":
  main()

# while loop
while True:
  print("hello, world)
  
# for loop
for i in range(50):
  print("hello, world")

# if statement
if x < y:
  print("x is less than y")
elif x > y:
  print("x is greater than y")
else:
  print("x is equal to y")
  
# Get rid of automatic \n
for i in range(4):
  print("?", end="")
print()
```

**C**
- source code -> compiler -> machine code

**Python**
- source code -> interpreter
- sourcecode -> compiler -> byte code -> interpreter

### Command line arg
```python
import sys

# First way
if len(sys.argv) == 2:
  print(f"hello, {sys.argv[1]}")

# Second way
for s in sys.argv:
  print(s)
  
# print argv char by char
for s in sys.argv:
  for c in s: # s is string
    print(c)  # c is character

# print only uppercase characters
from cs50 import get_string

s = get_string("name: ")
initials = ""
for c in s:
  if c.isupper(): # is c uppercase?
    initials += c
print(initials)
```

### Swap
```python
x = 1
y = 2
x , y = y , x
```

### Struct
```python
# student.py
class Student:
  def __init__(self, name, dorm):
    self.name = name
    self.dorm = dorm

# main.py
from cs50 import get_string
from student import Student

students = []

for i in range(3):
  name = get_string("Name: ")
  dorm = get_string("Dorm: ")
  s = Student(name, dorm)
  students.append(s)
  
for student in students:
  print(f"{student.name} lives in {student.dorm}")
```

### Dictionary
```python
class Dictionary:

  def __init__(self):
    self.words = set()
    
  def check(self, word):
    if word.lower() in self.words:
      return True
    else:
      return False
  
  def load(self, dictionary):
    file = open(dictionary, "r")
    for line in file:
      self.words.add(line.rstrip("\n"))
    file.close()
    return True
    
  def size(self):
    return len(self.words)
  
  def unload(self):
    return True
```
