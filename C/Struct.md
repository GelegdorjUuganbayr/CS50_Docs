# Structure
Unify several variables of different types into a single super variable

```C
struct car
{
  int year;
  char model[10];
  char plate[7];
  int odometer;
  double engine_size;
}
```

- Structure is typically defined in .h files or atop our programs outside of any functions
- This allows to create variables of that type using the familiar syntax
- We can access the various fields/members of structure using the dot operator

### Statically allocate
```C
// variable declaration
struct car mycar;

// access the member of struct
mycar.year = 2011;
strcpy(mycar.plate, "CS50");
mycar.odometer = 50505;
```

### Dynamically allocate
```C
// variable declaration
struct car *mycar = malloc(sizeof(struct car));

// access the member of struct
mycar->year = 2011;
strcpy(mycar->plate, "CS50");
mycar->odometer = 50505;
```

# Custom type
The keyword **typedef** creates a shorthand or rewritten name for data types.
```C
typedef <old name> <new name>;
typedef unsigned char byte;
typedef char* string;

struct car
{
  int year;
  char model[10];
  char plate[7];
  int odometer;
  double engine_size;
};
typedef struct car car_t;

typedef struct car
{
  int year;
  char model[10];
  char plate[7];
  int odometer;
  double engine_size;
}
car_t;
```

# Singly-Linked List
Combination of elements, when used in this way, a linked list.\
A linked list node is a special kind of struct with two members.
- Data of some data type (int, char, float)
- A pointer to anther node of the same type
```C
typedef struct sllist
{
  VALUE val;
  struct sllist* next; // cannot use sllnode because it has not been typedef-ed
}
sllnode
```

## Work with linked lists effectively
1. Create a linked list when it doesn't already exist
2. Search through a linked list to find an element
3. Insert a new node into the linked list.
4. Delete a single element from a linked list.
5. Delete an entire linked list.

### Create a linked list
```C
sllnode* create(VALUE val);
sllnode* new = create(6);
```

a. Dynamically allocate space for a new sllnode.
b. Check to make sure we didn't run out of memory.
c. Initialize the node's val field.
d. Initialize the node's next field.
e. Return a pointer to the newly created sllnode.

**Data visualisation**
|  6  | NULL|

### Search through a linked list to find an element
```C
bool find(sllnode* head, VALUE val);
bool exists = find(list, 6);
```

a. Create a traversal pointer pointing to the list's head
b. If the current node's val field is what we are looking for, report success
c. If not, set the traversal pointer to the next pointer in the list and go back to step b.
d. If you've reached the end of the list, report failure.

**Data visualisation**
|  2  |  *3  |
|  3  |  *5  |
|  5  |  *6  |
|  6  |  *8  |
|  8  | NULL |

### Insert a new node into the linked list

```C
sllnode* insert(sllnode* head, VALUE val);
```

a. Dynamically allocate space for a new sllnode.
b. Check to make sure we didn't run out of memory.
c. Populate and insert the node at the beginning of the linked list. (because it needs to traverse till end)
d. Return a pointer to the new head of the linked list.

**Data visualisation**
|  3  |  *5  | - new 
|  5  |  *6  |
|  6  |  *8  |
|  8  | NULL |

### Delete an entire linked list
```C
void detroy(sllnode* head);
```

a. If you've reached a null pointer, stop.
b. Delete the rest of the list.
c. Free the current node.

# Hash Tables
