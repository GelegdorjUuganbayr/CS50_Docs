# Sorts
## Computational Complexity
- O: Worst-case scenario
- Ω: Best-case scenario
- f(n): Measurement of algorithm

We can measure an algorithm based on how it handles these inputs. We don't actually care about what f(n) is precisely, but care only about its **tendency**, which is dictated by its higtest-order term.

| Complexity |    Explanation    |
| ---------- | ----------------- |
| O(1)       | Constant time     |
| O(log n)   | Logarithmic time  |
| O(n)       | Linear time       |
| O(n log n) | Linearithmic time |
| O(n^2)     | Quadratic time    |
| O(n^c)     | Polynomial time   |
| O(c^n)     | Exponential time  |
| O(n!)      | Factorial time    |
| O(\infty)  | Infinite time     |

## Sorts
### Selection Sort - O(n^2)
Find the **smallest** unsorted element in an array and swap it with the **first** unsorted element of the array.

#### [pseudocode]
```
Repeat until no unsorted elements remain:
  Search the unsorted part of the data to find the smallest value
  Swap the smallest found value with the first element of the unsorted part
```

### Bubble Sort - O(n^2)
Swap **adjaceent pairs** of elements if they are out of order, effectively "bubbling" larger elements to the right and smaller ones to the left.

#### [pseudocode]
```
Set swap counter to a non-zero value
Repeat until the swap counter is 0:
  Reset swap counter to 0
  Look at each adjacent pair
    if two adjacent elements are not in order, swap them and add one to the swap counter
```

### Insertion Sort - O(n^2)
Proceed once through the array from left-to-right, **shifting** elements as necesary to insert each element into its correct place.

#### [pseudocode]
```
Call the first element of the array "sorted"
Repeat until all elements are sorted:
  Look at the next unsorted element. Insert into the "sorted" portion by shifting the requisite number of elements.
```

## Merge Sort - O(n log n)
Split the full array into subarrays, then **merge** those subarray back together in the correct order.

#### [pseudocode]
```
Sort the left half of the array (assuming n > 1)
Sort the right half of the array (assuming n > 1)
Merge the two halves together
```


## Searches

### Linear Search - O(n)
**Iterate** across the array from left-to-right, trying to  find the target element.

#### [pseudocode]
```
Repeat, starting at the first element:
  if the first element is what you're looking for (the target), stop.
  Otherwise, move to the next element.
```

### Binary Search - O(log n)
Given a sorted array, **divide and conquer** by systematically eliminating half of the remaining elements in the search for the target element.\
To divide and conquer, reducing the search area by half each time, trying to find a target number.
- In order to leverage this power howerver, our array must first be sorted, else we cannot make assumptions about the array's contents.

#### [pseudocode]
```
Repeat until the (sub)array is of size 0:
  Calculate the middle point of the current (sub)array.
  If the target is at the middle, stop.
  Otherwise, if the target is less than what's at the middle, repeat, changing the end point to be just to the left of the middle.
  Otherwise, if the target is greater than what's at the middle, repeat, changing the start point to be just to the right of the middle.
```

## Recursion
In general, but not always, recursive function replace loops in non-recursive function.\
It is possible to have more than one base or recursive case, if the program might recurse or terminate in different ways, depending on the input being passed in.\
Every recursive function has two cases that could apply, given any input.
- The base case, which when triggered will terminate the recursive process
- The recursive case, which is where the recursion will actually occur.

### Factorial
Base case     : fact(1) = 1
recursive case: fact(n) = n * fact(n-1)

#### [C Code]
```cpp
int fact(int n)
{
  // Base case
  if (n == 1)
    return 1;
    
  // Recursive case
  else
    return n * fact(n-1);
}
```

### Fibonacci number
Multi base cases
- The first element is 0
- The second element is 1
- The nth element is the sum of the (n-1)th and (n-2)th elements.

### Collatz conjecture
It is pplies to positive integers and speculates that it is always possible to get **back to 1** if you follow these steps:
- If n is 1, stop
- Otherwise, if n is even, repeat this process on n/2
- Otherwise, if n is odd, repeat this process on 3n + 1

#### [C Code]
```cpp
int collatz(int n)
{
    // base case
    if (n == 1)
        return 0;
    // even numbers
    else if (n % 2 == 0)
        return 1 + collatz(n/2);
    // odd numbers
    else
        return 1 + collatz(n*3 + 1);
}
```

## Binary search
```cpp
bool search(int n, node*tree)
{
  if (tree == NULL)
    return false
  else if (n < tree->n)
    return search(n, tree->left);
  else if (n > tree->n)
    return search(n, tree->right);
  else
    true;
}
