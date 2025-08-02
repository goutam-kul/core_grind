#include <iostream>
#include <typeinfo>
using namespace std;


int main() {
    auto x = 42;
    auto y = 3.14;
    auto z = 'A';
    auto str = "Hello";


    cout << x << endl; 
    cout << y << endl;

    // Limitations
    // auto x;          // Error! Must have initializer
    // auto func(auto param);   // Error! Cannot use auto for function parameters
    return 0;
}

