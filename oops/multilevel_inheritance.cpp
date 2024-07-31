#include <iostream>
#include <memory>
using namespace std;

// Base class
class Base {
protected:
    int baseValue;
public:
    Base() : baseValue(0) {
        cout << "Base default constructor called" << endl;
    }

    // Parameterized constructor
    Base(int v) : baseValue(v) {
        cout << "Base parameterized constructor called with value: " << v << endl;
    }

    virtual ~Base() {
        cout << "Base destructor called" << endl;
    }

    void displayBase() const {
        cout << "Base value: " << baseValue << endl;
    }
};

class Intermediate : public Base {
protected:
    int intermediateValue;
public:
    Intermediate() : intermediateValue(0) {
        cout << "Intermediate default constructor called" << endl;
    }

    // Parameterized constructor
    Intermediate(int baseVal, int intVal) : Base(baseVal), intermediateValue(intVal) {
        cout << "Intermediate parameterized constructor called with base value: " << baseVal << " and intermediate value: " << intVal << endl;
    }

    virtual ~Intermediate() {
        cout << "Intermediate destructor called" << endl;
    }

    void displayIntermediate() const {
        cout << "Intermediate value: " << intermediateValue << endl;
    }
};

// Derived class
class Derived : public Intermediate {
private:
    int derivedValue;
public:
    Derived() : derivedValue(0) {
        cout << "Derived default constructor called" << endl;
    }

    // Parameterized constructor
    Derived(int baseVal, int intVal, int derVal) : Intermediate(baseVal, intVal), derivedValue(derVal) {
        cout << "Derived parameterized constructor called with base value: " << baseVal << ", intermediate value: " << intVal << ", and derived value: " << derVal << endl;
    }

    ~Derived() override {
        cout << "Derived destructor called" << endl;
    }

    void displayDerived() const {
        cout << "Derived value: " << derivedValue << endl;
    }
};

int main() {
    cout << "Start of main function" << endl;
    Base baseObj(1000);
    baseObj.displayBase();

    Intermediate intermediateObj(100,200);
    intermediateObj.displayBase();
    intermediateObj.displayIntermediate();

    Derived derivedObj(10, 20, 30);
    derivedObj.displayBase();
    derivedObj.displayIntermediate();
    derivedObj.displayDerived();

    cout << "End of main function" << endl;

    return 0;
}

/*
OUTPUT
Start of main function
Base parameterized constructor called with value: 1000
Base value: 1000
Base parameterized constructor called with value: 100
Intermediate parameterized constructor called with base value: 100 and intermediate value: 200
Base value: 100
Intermediate value: 200
Base parameterized constructor called with value: 10
Intermediate parameterized constructor called with base value: 10 and intermediate value: 20
Derived parameterized constructor called with base value: 10, intermediate value: 20, and derived value: 30
Base value: 10
Intermediate value: 20
Derived value: 30
End of main function
Derived destructor called
Intermediate destructor called
Base destructor called
Intermediate destructor called
Base destructor called
Base destructor called
*/