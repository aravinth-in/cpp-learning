#include <iostream>
#include "static_demo_class.hpp"

// Declaration of non-static function from file_1.cpp
void accessStaticFromFile1();

// The extern keyword in C++ is used to declare a variable or function that is defined in another translation unit (i.e., another source file).
// It tells the compiler that the variable or function exists, but its definition will be provided elsewhere.
// This is useful for sharing variables and functions across multiple files.

// Declaration of non-static global variable from file_1.cpp
extern int nonStaticGlobalVar;

// Definition of static member function (duplicate)
/*
duplicate symbol 'MyClass::staticFunction()' in:
    /var/folders/sm/1yhvfj5942x2yr8t7yp1q6yc0000gp/T/file_1-e4728f.o
    /var/folders/sm/1yhvfj5942x2yr8t7yp1q6yc0000gp/T/file_2-119406.o
ld: 1 duplicate symbol for architecture arm64
*/
/*void StaticDemoClass::staticFunction() {
    std::cout << "Static function defined in File2.cpp" << std::endl;
}*/

int main() {
    // Accessing static variable and function from file_1.cpp
    accessStaticFromFile1();

    // Accessing non-static global variable from file1.cpp
    std::cout << "Non-static global variable in file1.cpp: " << nonStaticGlobalVar << std::endl;

    // Trying to access static global variable directly (will cause an error)
    // std::cout << "Static global variable in file1.cpp: " << staticGlobalVar << std::endl; // Error

    // Trying to call static function directly (will cause an error)
    // staticFunction(); // Error

    return 0;
}


/*
OUTPUT
Static global variable in file_1.cpp: 42
Static function in file_1.cpp
Non-static global variable in file1.cpp: 100
*/