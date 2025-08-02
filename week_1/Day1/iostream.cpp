#include <iostream>
#include <iomanip>
using namespace std;

void booleanformatting(bool value) {
    cout << "With 'boolalpha' paramter: ";
    cout << boolalpha << value << endl;
    cout << "Without 'boolalpha': ";
    cout << value << endl;
    cout << "With 'noboolalpha': ";
    cout << noboolalpha << value << endl;
}

void floatformatting() {
    double pi = 3.14159265359;
    cout << "with 'fixed'" << fixed << setprecision(3) << pi << endl;
    cout << "with 'scientific'"  << scientific << setprecision(2) << pi << endl;
}

void numberbasis() {
    int num = 255;
    cout << "Decimal: " << dec << num << endl;
    cout << "Hex: " << hex << num << endl;
    cout << "Octal: " << oct << num << endl; 
}

int main() {
    // '>>' extraction operator (input)
    // '<<' insertion operator (output)

    cout << "Standard output" << endl;  
    cerr << "Error message" << endl;
    clog << "Log message" << endl;

    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "You entered: " << x << endl;

    cout << "=== Boolean formatting ===" << endl;
    booleanformatting(true);
    cout  << "=== Float formatting ===" << endl;
    floatformatting();
    cout << "=== Different Number basis ===" << endl;
    numberbasis();

    return 0;
}