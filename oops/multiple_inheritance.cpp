#include <iostream>
#include <string>
using namespace std;

// Base class 1
class MathOperations {
public:
    MathOperations(int v) {
        cout << "MathOperations constructor called" << endl;
    }

    virtual ~MathOperations() {
        cout << "MathOperations destructor called" << endl;
    }

    int add(int a, int b) {
        cout << "Performing addition: " << a << " + " << b << endl;
        return a + b;
    }
    
    int multiply(int a, int b) {
        cout << "Performing multiplication: " << a << " * " << b << endl;
        return a * b;
    }
};

// Base class 2
class StringManipulation {
public:
    StringManipulation() {
        cout << "StringManipulation constructor called" << endl;
    }

    virtual ~StringManipulation() {
        cout << "StringManipulation destructor called" << endl;
    }

    string concatenate(const string &a, const string &b) {
        cout << "Concatenating strings: \"" << a << "\" + \"" << b << "\"" << endl;
        return a + b;
    }

    void toUpperCase(string &str) {
        cout << "Converting string to uppercase: \"" << str << "\"" << endl;
        for (char &c : str) {
            c = toupper(c);
        }
    }
};

// Derived class
class Combined : public MathOperations, public StringManipulation {
public:
    // Constructor
    Combined() {
        cout << "Combined constructor called" << endl;
    }

    // Destructor
    ~Combined() override {
        cout << "Combined destructor called" << endl;
    }

    void performOperations() {
        cout << "Starting operations..." << endl;

        cout << "Sum: " << add(5, 3) << endl;
        cout << "Product: " << multiply(4, 2) << endl;

        string str1 = "Hello";
        string str2 = "World";
        cout << "Original strings: \"" << str1 << "\" and \"" << str2 << "\"" << endl;
        string concatenated = concatenate(str1, str2);
        cout << "Concatenated: " << concatenated << endl;

        toUpperCase(concatenated);
        cout << "Uppercase: " << concatenated << endl;

        cout << "Operations completed." << endl;
    }
};

int main() {

    MathOperations mathObj;
    int add = mathObj.add(1,2);
    int multiply = mathObj.multiply(3,4);
    cout << "Add: " << add << endl;
    cout << "Multiply: " << multiply << endl;

    StringManipulation stringObj;
    string concatenatedString = stringObj.concatenate("Hello", "Mars");
    cout << "Concatenated String: " << concatenatedString << endl;
    string originalString = "abcdef";
    cout << "Original String: " << originalString << endl;
    stringObj.toUpperCase(originalString);

    cout << "Concatenate: " << concatenatedString << endl;
    cout << "ToUpperCase: " << originalString << endl;

    Combined combinedObj;
    add = combinedObj.add(3,5);
    cout << "Add: " << add << endl;

    concatenatedString = stringObj.concatenate("Web", "3");
    cout << "Concatenated String: " << concatenatedString << endl;

    return 0;
}

/*
OUTPUT:
MathOperations constructor called
Performing addition: 1 + 2
Performing multiplication: 3 * 4
Add: 3
Multiply: 12
StringManipulation constructor called
Concatenating strings: "Hello" + "Mars"
Concatenated String: HelloMars
Original String: abcdef
Converting string to uppercase: "abcdef"
Concatenate: HelloMars
ToUpperCase: ABCDEF
MathOperations constructor called
StringManipulation constructor called
Combined constructor called
Performing addition: 3 + 5
Add: 8
Concatenating strings: "Web" + "3"
Concatenated String: Web3
Combined destructor called
StringManipulation destructor called
MathOperations destructor called
StringManipulation destructor called
MathOperations destructor called 
*/