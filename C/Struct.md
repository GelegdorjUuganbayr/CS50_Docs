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

**Data visualisation**\
|  2  |  *3  |\
|  3  |  *5  |\
|  5  |  *6  |\
|  6  |  *8  |\
|  8  | NULL |

### Insert a new node into the linked list

```C
sllnode* insert(sllnode* head, VALUE val);
```

a. Dynamically allocate space for a new sllnode.
b. Check to make sure we didn't run out of memory.
c. Populate and insert the node at the beginning of the linked list. (because it needs to traverse till end)
d. Return a pointer to the new head of the linked list.

**Data visualisation**\
|  3  |  *5  | - new \
|  5  |  *6  |\
|  6  |  *8  |\
|  8  | NULL |

### Delete an entire linked list
```C
void detroy(sllnode* head);
```

a. If you've reached a null pointer, stop.
b. Delete the rest of the list.
c. Free the current node.

# Hash Tables

# Tries
- map key-value pairs
  - keys: four-digit years (yyyy)
  - values: name of universities founded during those years.
- In a trie, the paths from a central root node to a leaf node, would be labeled with digits of the year
- Each node on the path from root to leaf could have 10 pointers emanating from it, one for each digit.

```C
typedef struct _trie
{
  char university[20];
  struct _trie* path[10];
}
trie;
```
Trade off
- big space of memory <-> quick insertion, deletion, and look-up

# Stacks
The data structure that is implemeted in one of two ways
- as an array
- as a linked list

When data is added to the stack, it sits **On top**. The most recently added element is the only element that can legally be removed.
- LIFO (Last in, first out)

Two operation that may legally be performed on a stack
- Push: Add a new element to the top of the stack
- Pop: Remove the most recently-added element from the top of the stack

```C
typedef struct _stack
{
  VALUE array[CAPACITY];
  int top;
}
stack;
```

Push() needs to:
- Accept a pointer to the stack.
- Accept data of type VALUE to be added to the stack.
- Add that data to the stack at the top of the stack.
- Change the location of the top of the stack.
```C
void push(stack* s, VALUE data);

stack s;
s.top = 0;
push(&s, 28); // s.top == 1
push(&s, 33); // s.top == 2
push(&s, 19); // s.top == 3
```

Pop() needs to:
- Accept a pointer to the stack
- Change the location of the top of the stack.
- Return the value that was removed from the stack.
```C
VALUE pop(stack* s);
int x = pop(&s); s.top == 2 [28, 33]
int x = pop(&s); s.top == 1 [28]
int x = pop(&s); s.top == 0 []
```

### Linked list based stack
```C
typedef struct _stack
{
  VALUE val;
  struct_stack *next;
}
stack;
```

Maintain a pointer to the head of the linked list

# Queue
When data is added to the queue, it is tacked onto the end, and so if an element needs to be removed, the element at the front is the only element that can legally be removed.
- FIFO (First in, first out)

Two operation that legally be performed on a queue
- Enqueue: Add a new element to the end of the queue.
- Dequeue: Remove the oldest element from the front of the queue.
```C
// Array based queue
typedef struct _queue
{
  VALUE array[CAPACITY];
  int front;
  int size;
}
queue;

queue q;
q.front = 0;
q.size = 0;
```

Enqueue() needs to:
- Accept a pointer to the queue.
- Accept data of type VALUE to be added to the queue.
- Add that data to the queue at the end of the queue.
- Change the size of the queue.
```C
void enqueue(queue *q, VALUE data);

enqueue(&q, 28); // q.front = 0, q.size = 1
enqueue(&q, 33); // q.front = 0, q.size = 2
enqueue(&q, 19); // q.front = 0, q.size = 3
```

Dequeue() needs to:
- Accept a pointer to the queue.
- Change the location of the front of the queue
- Decrease the size of the queue.
- Return the value that was removed from the queue.
```C
int x = dequeue(&q) // q.front = 1, q.size = 2
int x = dequeue(&q) // q.front = 2, q.size = 1
```

### Linked list based queue
```C
typedef struct _queue
{
  VALUE val;
  struct _queue *prev;
  struct _queue *next;
}
queue;
```

- Always maintain pointers to the head and tail of the linked list (global)
- Dynamically allocate a new node
- Set its next pointer to NULL, set its prev pointer to the tail
- Set the tail's next pointer to the new node
- Move the tail pointer to the newly-created node

