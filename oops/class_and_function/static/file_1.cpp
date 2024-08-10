#include <iostream>
#include "static_demo_class.hpp"

// Static global variable
static int staticGlobalVar = 42;

// Static function
static void staticFunction() {
    std::cout << "Static function in file_1.cpp" << std::endl;
}

// In C++, a non-static function can call a static function within the same translation unit (i.e., the same source file).
// The static keyword limits the visibility of the function to the file in which it is declared, 
// but it does not prevent other functions within the same file from calling it.

// Non-static function to access static variable and function
void accessStaticFromFile1() {
    std::cout << "Static global variable in file_1.cpp: " << staticGlobalVar << std::endl;
    staticFunction();
}

// Non-static global variable
int nonStaticGlobalVar = 100;

// Definition of static member function
void StaticDemoClass::staticFunction() {
    std::cout << "Static function defined in File1.cpp" << std::endl;
}

/*
 Uses of static:
 
 Visibility/Linkage:
 - File Scope: Limits visibility of global variables or functions to the file, preventing name conflicts in large projects.
 
 Static Member Variables and Functions in Classes:
 - Class Scope: Declares member variables and functions that belong to the class itself.
 - Static Member Variables: Shared among all instances of the class; only one copy exists.
 - Static Member Functions: Called on the class itself; can only access static members.
 
 Static Local Variables:
 - Function Scope: Retains value between function calls; initialized only once.
 */