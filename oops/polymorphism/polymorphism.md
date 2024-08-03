# Polymorphism in C++

Polymorphism is one of the four fundamental principles of Object-Oriented Programming (OOP), along with encapsulation, inheritance, and abstraction. Polymorphism allows objects of different classes to be treated as objects of a common superclass. It is a powerful feature that enables flexibility and the reuse of code.

## Types of Polymorphism

### 1. Compile-Time Polymorphism (Static Polymorphism)
Compile-time polymorphism is achieved through function overloading and operator overloading. The decision about which function or operator to invoke is made at compile time.

#### Function Overloading
Function overloading allows multiple functions with the same name but different parameters to be defined.

#### Operator Overloading
Operator overloading allows custom implementation of operators for user-defined types.

### 2. Run-Time Polymorphism (Dynamic Polymorphism)
Run-time polymorphism is achieved through inheritance and virtual functions. The decision about which function to invoke is made at run time.

#### Virtual Functions
A virtual function is a member function in the base class that you expect to override in derived classes. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function.

## Key Points

- **Function Overloading**: Same function name, different parameters.
- **Operator Overloading**: Custom implementation of operators for user-defined types.
- **Virtual Functions**: Functions in a base class that can be overridden in derived classes.
- **Pure Virtual Functions**: Functions with no implementation in the base class, making the class abstract.
- **Abstract Classes**: Classes that cannot be instantiated and are designed to be inherited by other classes.

## Advantages of Polymorphism

- **Flexibility**: Allows for the implementation of elegant software designs.
- **Maintainability**: Makes it easier to maintain and extend the code.
- **Reusability**: Promotes the reuse of code components.

## Disadvantages of Polymorphism

- **Complexity**: Can make the code more complex and harder to understand.
- **Performance Overhead**: Dynamic polymorphism can introduce a performance overhead due to the use of virtual functions.