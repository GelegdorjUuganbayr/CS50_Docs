# Dynamic Programming
Dynamic Programming records saves computation for reuse later
- Programming: in the optimization sense ("Linear Programming")
- Dynamic: it's impossible to use [it] in a pejorative way.
- A more descriptive term is **loom-up table**

## Rod Cutting
First rod-cutting strategy (brute-force)
- For every possible cut, compute the value of the left part plus the value of optimally cutting the right part. Take the best cut.

Second rod-cutting strategy (top-down)
- Find the value of optimal cut for right part in table
  - Compute it recursively if it doesn't exist yet
- Reduce computation from O(2^n) to O(n^2)
- Requires an array of length n to store intermediate computations.

Third rod-cutting strategy (bottom-up)
- Compute the value of a rod of length 1. Store it.
- Compute the value of a rod of length 2. You can only cut it into rods of length 1. The value of a rod of length 1 is already computed, so there is no recursion.
- Compute the value of successively longer rods up to length n. The optimal values of shorter rods are always computed first so there is no recursion.

### Image stitching

### Seam Carving
