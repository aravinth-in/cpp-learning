#include <iostream>
#include <string>

// Function Template
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Class Template
template <typename T>
class Pair {
public:
    Pair(T first, T second) : first_(first), second_(second) {}

    void print() const {
        std::cout << "Pair: (" << first_ << ", " << second_ << ")" << std::endl;
    }

private:
    T first_;
    T second_;
};

// Template Specialization for int
template <>
class Pair<int> {
public:
    Pair(int first, int second) : first_(first), second_(second) {}

    void print() const {
        std::cout << "Specialized Pair for int: (" << first_ << ", " << second_ << ")" << std::endl;
    }

private:
    int first_;
    int second_;
};

// Variadic Template Function
// Base case: no arguments
// This function is called when there are no more arguments left in the parameter pack.
// It terminates the recursion by providing a stopping condition.
void print() {
    std::cout << std::endl;
}

template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    print(args...); // Recursive call with remaining arguments
}

int main() {
    std::cout << "Add integers: " << add(3, 4) << std::endl;
    std::cout << "Add doubles: " << add(3.5, 4.5) << std::endl;
    std::cout << "Add strings: " << add(std::string("Hello, "), std::string("World!")) << std::endl;

    Pair<double> doublePair(3.5, 4.5);
    doublePair.print();

    Pair<int> intPair(3, 4);
    intPair.print();

    std::cout << "Variadic template function output: ";
    print(1, 2.5, "Hello", 'A');

    return 0;
}


/*
OUTPUT
Add integers: 7
Add doubles: 8
Add strings: Hello, World!
Pair: (3.5, 4.5)
Specialized Pair for int: (3, 4)
Variadic template function output: 1 2.5 Hello A 
*/