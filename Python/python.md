# Python
### Variabls
- no type specifier
- Declared by initialization only

### Conditionals
| C       | Python |
|---------|--------|
| ||      | or     |
| &&      | and    |
| else if | elif   |
| !       | not    |

### List (Array)
- Lists are not fixed in size, it can grow or shrink as needed.
- You can always tack extra elements onto your array and splice things in and out easily.
- Declareing a list
  - nums = [] == nums = list()
  - nums = [1, 2, 3, 4]
  - nums = [x for x in range(500)] #[0, ... ,499]
- append
  - nums.append(5)    # append value at the last
  - nums.insert(4, 5) # insert value at fourth location
  - nums[len(nums):] = [5] # same as append
  
### Tuples
- Tuples are ordered, immutable sets of data.
- It's great for associating collections of data (like struct in C).
- Values are unlikely to change.

**List of Tuples**
```python
presidents = [
  ("George Washington", 1789),
  ("John Adams", 1797),
  ("Thomas Jefferson", 1801),
  ("James Madison", 1809)
]

# Iteration
for prez, year in presidents:
  print("In {1}, {0} took office".format(prez, year)) # {1} == year, {0} == prez
```

### Dictionaries
- Dictionary allows you to specify list indices with words or phrases (keys), instead of integers.
- { key : value }
- When it is iterated, the order is not gueranteed.
```python
pizzas = {
  "cheese" : 9,
  "pepperoni" : 10,
  "vegetable" : 11,
  "buffalo chicken" : 12
}

pizzas["cheese"] = 8    # change a value of the key
if pizza["vegetables"] <12:
  # do something
pizzas["bacon"] = 14    # adding new key and value

# Iteration
for pie in pizzas:  # pie is key of dictionary
  print(pie)        # print keys
  
for pie, price in pizzas.items():
  print(price)      # print values
  print("A whole {} pizza costs ${}".format(pie, price))  # print keys and values
  print("A whole " + pie + " pizza costs $" + str(price))
```

### Functions
- We don't need to return type of the function and the data types of any parameters
- All functions are introduced with the def keyword.
- No need for main
- If you want to define main:
```python
if __name__ == "__main__":
  main()
```

**Defining the function**
```python
def square(x):
  result = 0
  for i in range(0,x):
    result += x
  return result
  
print(square(5))
```

### Objects
- python is an object-oriented programming language.
- Objects have properties
- Objects also have hethods; functions that are inherent to the object
- Define a type of object using the **class** keyword
- self should be its first parameter, which stipulates on what object the method is called.

**Declaring the class**
```python
class Student():

  def __init__(self, name, id):
    self.name = name
    self.id = id
    
  def changeID(self, id):
    self.id = id
    
  def print(self):
    print("{} - {}".format(self.name, self.id)
```

---

## Comparison with C

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
