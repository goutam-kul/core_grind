#### Day-1
###### iostream
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

###### const keyword 
The `const` keyword makes variable immutable. 

###### auto keyword
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

#### Day-2
##### Functions & Function Overloading 
- Function are **block of reusable code** that performs a **specific task**. They follow the **DRY** principle and makes the code much cleaner, modular and maintainable.
```c++
int add(int a, int b) {
    return a + b;
}
```
- **Function parameters** can **passed by value** or **pass by reference** in c++. Pass by value is when you get a copy of the variable. While in pass by reference you get direct access to the modify the variable. 
- **Inline function** defined like this : 
```c++
inline int max(int a, int b) {
    return (a > b) ? a : b;
}
```
- The benefit of these functions is that the compiles replaces the function call with the function's code at the call site during compilation. So the function call doesn't goes to the call stack.

##### Function Overloading
- Function overloading allows you to define multiple functions with the same name
```c++
int add(int a, int b) { return a + b; };
int add(int a, int b, int c) { return a + b + c; };
```
- The compiler determines which function to call based on the arguments provided(type, number of arguments).
i
```Namespaces revisit on Day-3 and Day-4, since Day-3 is OOP and namespaces are heavly Object Oriented.```

#### Day-3
