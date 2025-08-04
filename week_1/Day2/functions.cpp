#include <iostream>
using namespace std;

// Pass by value - creates a copy 
void modifyValue(int x) {
    x = 100;
    cout << "Inside modiyfValue: x = " << x << endl;
}

// Pass by reference - original value
void modifyRef(int& x) {
    x = 100;
    cout << "Inside modifyRef: x = " << x << endl;
} 


// Function pointers 
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
// Function that takes another function as parameter
int calculate(int a, int b, int (*opeartion)(int, int)) {
    return opeartion(a, b);
}


// Inline functions 
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function Overloading 
// Function overloading allows you to define multiple functions witht the same name
// The catch is number of parameters and parameter type 
// The compiler determines which function to call based on the arguments provided

// Basic function overloading
void print(int value) {
    cout << "Integer: " << value << endl;
}

void print(double value) {
    cout << "Double: " << value << endl;
}
// Overloading based on number of parameters 
int addition(int a, int b) {
    cout << "Adding two integers: " << endl;
    return a + b;
}

int addition(int a, int b, int c) {
    cout << "Adding three integers: " << endl;
    return a + b + c;
}


int main() {
    int x = 10;
    
    // Call pass by value 
    modifyValue(x);

    // Outside function
    cout << "Outside modifyValue: x = " << x << endl;

    // Call pass by ref
    modifyRef(x);

    // Final value of 'number'
    cout << "Final value: x = " << x << endl;

    // Function pointer declaration and assignment 
    int (*funcPtr)(int, int) = add;

    cout << "Using function pointer: " << funcPtr(3, 5) << endl;

    // Change what functpr points to 
    funcPtr = multiply;
    cout << "Using function pointer as multiple: " << funcPtr(3, 5) << endl;

    // Pass function as argument 
    cout << "Calculate with add: " << calculate(3, 5, add) << endl;
    cout << "Calculate with multiply: " << calculate(3, 5, multiply) << endl;


    // FUnction overloading calls 
    int a = 10, b = 20, c = 30;
    double val = 3.14;
    
    print(a);
    print(val);

    cout << addition(a, b) << endl;
    cout << addition(a, b, c) << endl;
    
    
    return 0;
}