#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void basicLambda() {
    auto sum = [](int a, int b){
        return a+b;
    };
    
    std::cout << "Sum: " << sum(3,4) << std::endl;
}

void captureByValue() {
    int x = 10;
    auto printX = [x]() {
        std::cout << "Captured by value: " << x << std::endl;
    };
    x = 20; // Changing x after capturing
    printX(); // Output will still be 10
}

void captureByReference() {
    int x = 10;
    auto printX = [&x]() {
        std::cout << "Captured by reference: " << x << std::endl;
    };
    x = 20; // Changing x after capturing
    printX(); // Output will be 20
}

void captureAll() {
    int x = 10;
    int y = 20;
    auto printAllByValue = [=]() {
        std::cout << "Captured by value: x = " << x << ", y = " << y << std::endl;
    };
    auto printAllByReference = [&]() {
        std::cout << "Captured by reference: x = " << x << ", y = " << y << std::endl;
    };
    x = 30;
    y = 40;
    printAllByValue(); // Output will be x = 10, y = 20
    printAllByReference(); // Output will be x = 30, y = 40
}

// Without mutable: The captured variable cannot be modified inside the lambda.
// With mutable: The captured variable can be modified inside the lambda, but these 
// modifications do not affect the original variable outside the lambda.
void mutableLambda() {
    int x = 10;
    auto modifyX = [x]() mutable {
        x = 20;
        std::cout << "Inside lambda: x = " << x << std::endl;
    };
    modifyX(); // Output will be x = 20
    std::cout << "Outside lambda: x = " << x << std::endl; // Output will be x = 10
}

void lambdaAsParameter() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto print = [](int n) {
        std::cout << n << " ";
    };
    // std::for_each: Applies the given function to a range of elements.
    std::for_each(numbers.begin(), numbers.end(), print);
    std::cout << std::endl;
}

// std::function: A standard library template that can store any callable target 
// (functions, lambda expressions, bind expressions, or other function objects) that matches the specified signature.
// int(int, int): The signature of the callable object. It specifies that the callable object takes 
// two int parameters and returns an int.
std::function<int(int, int)> getAdder() {
    return [](int a, int b) {
        return a + b;
    };
}

void returnLambda() {
    auto add = getAdder();
    std::cout << "Sum: " << add(5, 7) << std::endl;
}

int main() {
    basicLambda();
    captureByValue();
    captureByReference();
    captureAll();
    mutableLambda();
    lambdaAsParameter();
    returnLambda();
    return 0;
}


/*
Capture Clause []:
[]: Capture nothing.
[=]: Capture all variables by value.
[&]: Capture all variables by reference.
[x]: Capture the variable x by value.
[&x]: Capture the variable x by reference.
[=, &y]: Capture all variables by value, but capture y by reference.
[&, x]: Capture all variables by reference, but capture x by value.
*/

/*
OUTPUT
Sum: 7
Captured by value: 10
Captured by reference: 20
Captured by value: x = 10, y = 20
Captured by reference: x = 30, y = 40
Inside lambda: x = 20
Outside lambda: x = 10
1 2 3 4 5 
Sum: 12
*/