#### Day-1
###### `iostream`
`iostream` is the standard C++ library for input and output operations. It provides stream based I/O through objects like `cin`, `cout`, `cerr` and `clog`.



###### References 
- A reference is an alias to an already existing variable. Once initialized to a variable a reference can't refer to anyother variables. It is permanantly bound to its first object. In very simple terms, instead of getting a copy or a pointer to the object, you can directly access the object and modify it. 

```c 
int x = 100;
int& refX = x;  // ref is now an alias (reference) to x
```

**Key Properties for Reference**
1. **Must be initialized** when declared
2. **Cannot be reassigned** to any other object 
3. **No Null reference** (unlike pointers)
4. **Same memory address** as the original objecti

###### `const` keyword 
The `const` keyword makes variable immutable. 

###### 'auto` keyword
`auto` tells the compiler to **automatically deduce** the type of varialbe from its initializer. It makes code more readable and maintainable.
```c++
auto x = 42;        // int
auto y = 3.14;      // double 
auto z = 'A';       // char
auto str = "Hello"; // const char*

vector<int> numbers = {1, 2, 4};
// Instead of: vector<int>:iterator it = numbers.begin();
auto it  = numbers.begin();
```
When to use `auto`:
1. **When type is obvious** from context
2. **Iterator declaration**

When to not use `auto`:
1. **When type clarity is important** 