#include <iostream>
#include <type_traits>

// Static Member Variables
class Counter {
public:
    static int count;

    Counter() {
        count++;
    }

    static void showCount() {
        std::cout << "Count: " << count << std::endl;
    }
};

int Counter::count = 0;

// Static Member Functions
class Math {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

// Static Local Variables
void increment() {
    static int count = 0;
    count++;
    std::cout << "Local Count: " << count << std::endl;
}

// Static Global Variables
static int globalVar = 10;

void printGlobalVar() {
    std::cout << "GlobalVar: " << globalVar << std::endl;
}

// Static Functions (File Scope)
static void helperFunction() {
    std::cout << "Helper function called!" << std::endl;
}

// Static Methods in Utility Classes
class MathUtils {
public:
    static int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
};

// Static Variables in Namespaces
namespace MyNamespace {
    static int counter = 0;

    void increment() {
        counter++;
    }

    void printCounter() {
        std::cout << "Namespace Counter: " << counter << std::endl;
    }
}

int main() {
    // Static Member Variables
    Counter c1;
    Counter c2;
    Counter::showCount(); // Output: Count: 2

    // Static Member Functions
    std::cout << "Sum: " << Math::add(3, 4) << std::endl; // Output: Sum: 7

    // Static Local Variables
    increment(); // Output: Local Count: 1
    increment(); // Output: Local Count: 2

    // Static Global Variables
    printGlobalVar(); // Output: GlobalVar: 10

    // Static Functions (File Scope)
    helperFunction(); // Output: Helper function called!

    // Static Methods in Utility Classes
    std::cout << "Factorial of 5: " << MathUtils::factorial(5) << std::endl; // Output: Factorial of 5: 120

    // Static Variables in Namespaces
    MyNamespace::increment();
    MyNamespace::printCounter(); // Output: Namespace Counter: 1

    return 0;
}