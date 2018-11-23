# Casting
### Static Cast
Static Cast is used to convert from one type to another
- They should not be used to cast between pointer and non pointer types.
- There is no run time check to ensure the cast results in a full type of the target type.
    - User has to ensure the type cast is safe.
### Const Cast
Const Cast is used to add or remove the const modifier to a variable
- It allows the developer to make:
    - A non modifiable variable modifiable
    - A modifiable variable non modifiable
- It can be used to change a variables volatile modifier
    - Volatile is used to tell the compiler the variable can be modified by another process
    - When it is used it should check the value every time instead of storing it in the cache and re using it

### Dynamic cast
Dynamic cast does a run time type check when performing the cast
- It is safer to use when you know less about the types involved

### Reinterpret cast
Reinterpret cast will convert pointers between types and integers.
- Reinterpret cast does not check the pointer type or the type pointed to
- It is possible to cast between unrelated and incompatible types
    - Any dereference of the cast is likely to fail, thus reinterpret cast is not safe.

