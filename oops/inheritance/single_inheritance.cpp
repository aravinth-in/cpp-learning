#include <iostream>
#include <memory> 

using namespace std;


class Base {
private:
    int value;

public:
    Base() : value(0) {
        cout << "Base constructor called" << endl;
    }

    virtual ~Base() {
        cout << "Base destructor called" << endl;
    }

    void setValue(int v) {
        value = v;
    }

    void displayValue() const {
        cout << "Base value: " << value << endl;
    }

    virtual void showDetails() const {
        displayValue();
    }
};

class Derived : public Base {
private:
    int additionalValue;

public:
    Derived() : additionalValue(0) {
        cout << "Derived constructor called" << endl;
    }

    ~Derived() override {
        cout << "Derived destructor called" << endl;
    }

    void setAdditionalValue(int v) {
        additionalValue = v;
    }

    void displayAdditionalValue() const {
        cout << "Derived additional value: " << additionalValue << endl;
    }

    // Overriding base class function
    void showDetails() const override {
        Base::showDetails();
        displayAdditionalValue();
    }
};

int main() {
    Base baseObj;
    baseObj.setValue(489);
    baseObj.displayValue();

    // Use smart pointer to manage Derived object
    unique_ptr<Derived> derivedObj = make_unique<Derived>();
    derivedObj->setValue(10);
    derivedObj->setAdditionalValue(20);
    derivedObj->displayAdditionalValue();
    derivedObj->showDetails();
    return 0;
}

/*
OUTPUT
Base constructor called
Base value: 489
Base constructor called
Derived constructor called
Derived additional value: 20
Base value: 10
Derived additional value: 20
Derived destructor called
Base destructor called
Base destructor called
*/