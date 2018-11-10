# Dynamic Memory Allocation
- We can use pointers to get access to a block of **dynamically allocated memory** at runtime.
- Dynamically allocated memory comes from a pool of memory known as the **heap.**
- Prior to this point, most of memory you've been working with has comming from the memory **stack**.

|          Memory         |
|:-----------------------:|
|           text          |
|     Initialised data    |
|    Uninitialised data   |
| Heap<br>↓<br>↑<br>Stack |
|  Environment Variables  |

- We get dynamically-allocated memory by making a call the function **malloc()**, passing as its parameter the number of bytes requested.
- After obtaining memory for you, **malloc()** will return a **pointer** to that memory.
- If **malloc()** cannot give you memory, it will return NULL.

## Allocating Dynamic Memory
```cpp
// Statically obtain an interger
intx;
// Dynamically obtain an interger
int *px = malloc(sizeof(int));

// Declare new array based on usr input
int x = GetInt();
float stack_array[x];
float *heap_array = malloc(x * sizeof(float));

// Memory allocation
char *word = malloc(50 * sizeof(char));
// Free the allocated memory.
free(word);
```

Trouble: Dynamically-allocated memory is not automatically returned to the system for later use when the function in which it's created finishes execution.
- Failing to return memory back to the system, it results in a **memory leak** which can compromise your system's performance.
- When you finish working with dynamically-allocated memory, you must **free()** it.
- Do not free twice.

### realloc
```cpp
// If number not found in list, add to list
if (!found)
{
  // Check whether enough space for number
  if (size == capacity)
  {
    // Allocate space for number
    number = realloc(numbers, sizeof(int) * (size + 1));
    if (!numbers)
    {
      return 1;
    }
    capacity++
  }
  
  // Add number to list
  number[size] = number;
  size++
}
```

- Processing time is linear since it allocate memory and copy the values

### node
```cpp
typedef struct node
{
  int number;
  struct node *next;
}
node;

int main(void)
{
  // memory for numbers
  node *numbers = NULL;
  
  while (true)
  {
  
  // Check whether number is already in list
  bool found = false;
  for (node *ptr = numbers; ptr != NULL; ptr = ptr->next)
  {
    if (ptr->number == number)
    {
      found = true;
      break;
    }
  }
  
  if (!found)
  {
    // Allocate space for number
    node *n = malloc(sizeof(node));
    
    // Add number to list
    n->number = number;
    n->next = NULL;
    if (numbers)
    {
      for (node *ptr = numbers; ptr != NULL; ptr = ptr->next)
      {
        if (!ptr->next) // ptr->next == NULL
        {
          ptr->next = n;
          break;
        }
      }
    }
    else
    {
      numbers = n;
    }
  }
  // Free memory
  node *ptr = numbers;
  while (ptr != NULL)
  {
    node *next = ptr->next;
    free(ptr);
    ptr = next;
  }
}
  
  
```
