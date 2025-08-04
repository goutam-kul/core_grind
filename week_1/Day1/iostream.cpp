#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
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
void input_line() {
    string line;

    // Clear input buffer before getline 
    cin.ignore();
    
    cout << "Enter a line: ";
    getline(cin, line);

    cout << "You entered: " << line << endl;
}

// Stream states and Error Handling 
void stream_states() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    // Check if input was successful 
    if (cin.fail()) {
        cout << "Invalid input!" << endl;
        cin.clear();        // Clear error state 
        cin.ignore(1000, '\n');  // Clear input buffer, ignores input values up to 1000 characters.
    } else {
        cout << "You entered: " << number << endl;
    }
}

void fileIO() {
    // Writing to file
    ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << "Hello, world!" << endl;
        outFile << "This is line 2" << endl;
        outFile.close();
    }

    cout << "Writing completed to file 'output.txt'" << endl;

    // Reading from file
    ifstream inFile("output.txt");
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    
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

    input_line();
    stream_states();
    fileIO();
    
    return 0;
}