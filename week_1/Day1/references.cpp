#include <iostream>
using namespace std;

// Function prototypes 
void func1(int x);
void func2(int& x);
int& getElement(int arr[], int index);

int main() {
    int original = 42;
    int& alias = original;  // alias is a reference to original 
    
    cout << "Original: " << original << endl;   // 42
    cout << "Alais: " << alias << endl;
    cout << "Address of original: " << &original << endl;
    cout << "Address of Alias: " << &alias << endl;
    
    // Modifying through reference affects original 
    alias = 100;
    cout << "Original: " << original << endl;   // 42
    cout << "Alais: " << alias << endl;
    cout << "Address of original: " << &original << endl;
    cout << "Address of Alias: " << &alias << endl;


    // Pass by value func
    int num = 42;
    func1(num);
    cout << num << endl;    // Value stays same 42

    // Pass by reference function
    func2(num);
    cout << num << endl;    // Changed to 100


    // Modifying through pointers 
    int x = 12;
    int* ptr = &x;

    *ptr = 10;
    cout << *ptr << endl;

    // Return by reference
    int numbers[] = {1, 2, 3, 4, 5};
    getElement(numbers, 1) = 100;
    cout << *(numbers + 1) << endl;

    return 0; 
}

// Pass by value 
void func1(int x) {
    x = 100; // Only changes, local copy 
}

// Pass by reference 
void func2(int& x) {
    x = 100; // Changes the original variable 
}

// Return by reference 
int& getElement(int arr[], int index) {
    return arr[index];
}