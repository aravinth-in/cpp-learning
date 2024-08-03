#include <iostream>
#include <string>
using namespace std;

class Calculator {
public:
    // Function to add two integers
    int add(int a, int b) {
        cout << "Adding two integers: " << a << " + " << b << endl;
        return a + b;
    }

    // Function to add three integers
    int add(int a, int b, int c) {
        cout << "Adding three integers: " << a << " + " << b << " + " << c << endl;
        return a + b + c;
    }

    // Function to add two double values
    double add(double a, double b) {
        cout << "Adding two doubles: " << a << " + " << b << endl;
        return a + b;
    }

    // Function to add two strings
    string add(string a, string b) {
        cout << "Concatenating two strings: " << a << " + " << b << endl;
        return a + b;
    }
};


int main() {
    Calculator calc;
    cout << "Result: " << calc.add(1, 2) << endl;              // Overload for two integers
    cout << "Result: " << calc.add(1, 2, 3) << endl;           // Overload for three integers
    cout << "Result: " << calc.add(1.1, 2.2) << endl;          // Overload for two doubles
    cout << "Result: " << calc.add("Hello", " C++") << endl;   // Overload for two strings
    return 0;
}


/*
OUTPUT
Result: Adding two integers: 1 + 2
3
Result: Adding three integers: 1 + 2 + 3
6
Result: Adding two doubles: 1.1 + 2.2
3.3
Result: Concatenating two strings: Hello +  C++
Hello C++
*/