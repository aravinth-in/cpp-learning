#include <iostream>
#include <memory> 

using namespace std;


class Base {
protected:
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
    // Use smart pointer to manage Derived object
    unique_ptr<Derived> obj = make_unique<Derived>();
    obj->setValue(10);
    obj->setAdditionalValue(20);
    obj->showDetails();

    return 0;
}
