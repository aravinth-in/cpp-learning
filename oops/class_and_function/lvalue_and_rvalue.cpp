#include <iostream>
#include <cstring>

// Function to handle lvalue references
void determineValueCategory(int& lval) {
    std::cout << "Lvalue reference: " << lval << std::endl;
}

// Function to handle rvalue references
void determineValueCategory(int&& rval) {
    std::cout << "Rvalue reference: " << rval << std::endl;
}

// Widget class demonstrating copy and move semantics
class Widget
{
public:
    Widget()
    {
        std::cout << "Default constructor" << std::endl;
    }

    Widget(const Widget &other)
    {
        std::cout << "Copy constructor" << std::endl;
    }

    Widget(Widget &&other) noexcept
    {
        std::cout << "Move constructor" << std::endl;
    }

    void determineValueCategory(Widget &lval)
    {
        std::cout << "Processing lvalue" << std::endl;
    }

    void determineValueCategory(Widget &&rval)
    {
        std::cout << "Processing rvalue" << std::endl;
    }
};

int main()
{
    int a = 5;
    determineValueCategory(a); // 'a' is an lvalue

    determineValueCategory(10); // '10' is an rvalue
    determineValueCategory(5 + 5); // '5 + 5' is an rvalue

    Widget obj1;
    Widget obj2 = obj1; // Copy constructor

    // std::move indicates that obj1 can be "moved from," treating it as an rvalue. 
    // This allows the move constructor to transfer its resources to obj3 rather than copying them, 
    // optimizing performance by avoiding unnecessary deep copies.
    Widget obj3 = std::move(obj1); // Move constructor

    obj2.determineValueCategory(obj2); // Lvalue reference
    obj3.determineValueCategory(std::move(obj3)); // Rvalue reference

    return 0;
}


/*
OUTPUT
Lvalue reference: 5
Rvalue reference: 10
Rvalue reference: 10
Default constructor
Copy constructor
Move constructor
Processing lvalue
Processing rvalue
*/