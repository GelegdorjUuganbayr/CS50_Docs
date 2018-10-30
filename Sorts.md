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
To find the smallest unsorted element and add it to the end of the sorted list.

#### [pseudocode]
```
Repeat until no unsorted elements remain:
  Search the unsorted part of the data to find the smallest value
  Swap the smallest found value with the first element of the unsorted part
```

### Bubble Sort - 
To move higher valued elements generally towards the right and lower value elements generally towards the left.

#### [pseudocode]
```
Set swap counter to a non-zero value
Repeat until the swap counter is 0:
  Reset swap counter to 0
  Look at each adjacent pair
    if two adjacent elements are not in order, swap them and add one to the swap counter
```
