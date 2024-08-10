// Include guards to prevent multiple inclusions of this header file
// #ifndef STATIC_DEMO_CLASS_HPP: This line checks if the macro STATIC_DEMO_CLASS_HPP is not defined.
// If it is not defined, the code between #ifndef and #endif will be included.
// #define STATIC_DEMO_CLASS_HPP: This line defines the macro STATIC_DEMO_CLASS_HPP.
// This ensures that if the header file is included again in the same translation unit,
// the code between #ifndef and #endif will be skipped.

// Alternatively, you can use #pragma once to achieve the same effect in a simpler way:
// #pragma once: This directive ensures that the file is included only once by the compiler.

#ifndef STATIC_DEMO_CLASS_HPP
#define STATIC_DEMO_CLASS_HPP

class StaticDemoClass {
public:
    static void staticFunction(); // Declaration of static member function
};

#endif // STATIC_DEMO_CLASS_HPP