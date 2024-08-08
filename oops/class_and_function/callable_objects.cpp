#include <iostream>
#include <functional>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>

// Function Pointer
// A function pointer is a variable that stores the address of a function that can be called later.
void functionPointerExample() {
    std::cout << "Function Pointer called!" << std::endl;
}

// std::function
// std::function is a versatile wrapper for any callable target (function, lambda, bind expression, or other function objects).
void stdFunctionExample() {
    std::cout << "std::function called!" << std::endl;
}

// Lambda Expression
// Lambdas are anonymous functions that can capture variables from their enclosing scope.
auto lambdaExample = []() {
    std::cout << "Lambda called!" << std::endl;
};

// Member Function Pointer
// Member function pointers are used to call member functions of a class.
class MyClass {
public:
    void memberFunction() {
        std::cout << "Member function called!" << std::endl;
    }
};

// Functor
// A functor (or function object) is an object that can be treated as though it is a function or function pointer.
class Functor {
public:
    void operator()() {
        std::cout << "Functor called!" << std::endl;
    }
    
    void callFunction() {
        std::cout << "Member function called by functor!" << std::endl;
    }
};

// Virtual Function
// Virtual functions allow derived classes to override methods in a base class.
class Base {
public:
    virtual void virtualFunction() {
        std::cout << "Base virtual function called!" << std::endl;
    }
};

class Derived : public Base {
public:
    void virtualFunction() override {
        std::cout << "Derived virtual function called!" << std::endl;
    }
};

// std::bind
// std::bind creates a callable object that binds arguments to a function.
void bindExampleFunction(int a, int b) {
    std::cout << "std::bind called with arguments: " << a << ", " << b << std::endl;
}

int main() {
    // Function Pointer
    void (*funcPtr)() = functionPointerExample;
    funcPtr();

    // std::function
    std::function<void()> stdFunc = stdFunctionExample;
    stdFunc();

    // Lambda Expression
    lambdaExample();

    // Member Function Pointer
    MyClass obj;
    void (MyClass::*memFuncPtr)() = &MyClass::memberFunction;
    (obj.*memFuncPtr)();

    // Functor
    Functor functor;
    functor();
    functor.callFunction();

    // Virtual Function
    Base* basePtr = new Derived();
    basePtr->virtualFunction();
    delete basePtr;

    // std::bind
    auto boundFunction = std::bind(bindExampleFunction, 10, 20);
    boundFunction();

    return 0;
}


/*
OUTPUT
Function Pointer called!
std::function called!
Lambda called!
Member function called!
Functor called!
Member function called by functor!
Derived virtual function called!
std::bind called with arguments: 10, 20
*/