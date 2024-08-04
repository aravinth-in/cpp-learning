#include <iostream>
#include <memory>
#include <vector>
using namespace std;


// Abstract Classes: These classes cannot be instantiated and are meant to be subclassed. 
// They often contain one or more pure virtual functions (in C++) or abstract methods (in other languages).
class AbstractShape {
protected:
    double color; // Member variable to store color

public:
    AbstractShape(double c) : color(c) {} // Constructor to initialize color

    virtual double area() const = 0; // Pure virtual function
    virtual void draw() const = 0; // Pure virtual function
    virtual ~AbstractShape() = default; // Virtual destructor to ensure derived class destructors are called

    void commonFunction() const {
        cout << "Common functionality with color: " << color << endl;
    }
};


// Interface Classes: These are similar to abstract classes but typically only contain pure virtual functions or abstract methods. 
// They define a contract that other classes must follow.
class IShape {
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;
    virtual ~IShape() = default;
};

/*
Key Differences between Abstract and Interface Class:
Member Functions:
- Abstract Class: Can have both pure virtual functions and regular member functions.
- Interface Class: Typically only has pure virtual functions.

Member Variables:
- Abstract Class: Can have member variables.
- Interface Class: Typically does not have member variables.

Purpose:
- Abstract Class: Used to provide a common base with some shared implementation.
- Interface Class: Used to define a strict contract without any implementation.
*/


// Singleton Classes: These classes are designed to ensure that only one instance of the class can exist. 
// They provide a global point of access to that instance.
class Singleton {
private:
    static Singleton* instance;
    Singleton() {} // Private constructor

public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() const {
        cout << "Singleton instance accessed" << endl;
    }
};

// Initialize the static member variable 'instance' to nullptr
// This is necessary to ensure that the Singleton instance is created only once
// and to provide a global point of access to the Singleton instance.
// This initialization should be done in the .cpp file.

// One Definition Rule (ODR): C++ enforces the One Definition Rule, which states that there should be exactly 
// one definition of any variable, function, class, etc., in the entire program. If you put the initialization 
// in the header file (.hpp), and this header is included in multiple translation units (i.e., .cpp files), 
//it will result in multiple definitions of the static member variable, leading to linker errors.
Singleton* Singleton::instance = nullptr;


// Static Classes: These classes cannot be instantiated and typically contain only static members. 
// They are used to group related static methods and properties.
class MathUtils {
public:
    static double add(double a, double b) {
        return a + b;
    }

    static double multiply(double a, double b) {
        return a * b;
    }
};


// Final Classes: These classes cannot be subclassed. They are used to prevent further inheritance.
class FinalShape final {
public:
    void draw() const {
        cout << "Drawing a final shape" << endl;
    }
};


// Nested Classes: These are classes defined within another class. 
// They can be used to logically group classes that are only used in one place.
class OuterClass {
public:
    class NestedClass {
    public:
        void display() const {
            cout << "Inside Nested Class" << endl;
        }
    };
};


// Concrete class: Circle
// Concrete Classes: These are classes that provide implementations for all of their inherited abstract methods. 
// They can be instantiated and used to create objects.
class Circle : public AbstractShape {
private:
    double radius;
public:
    Circle(double r, double c) : AbstractShape(c), radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        cout << "Drawing a circle with radius: " << radius << endl;
    }
};


// Concrete class: Rectangle
class Rectangle : public AbstractShape {
private:
    double width, height;
public:
    Rectangle(double w, double h, double c) : AbstractShape(c), width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void draw() const override {
        cout << "Drawing a rectangle with width: " << width << ", height: " << height << " and color: " << color << endl;
    }
};


// Concrete class: Triangle
// This class inherits from the IShape interface, so it must implement all the pure virtual functions in the interface
class Triangle : public IShape {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }

    void draw() const override {
        cout << "Drawing a triangle with base: " << base << " and height: " << height << endl;
    }
};


int main() {
    // Singleton usage
    Singleton* singleton = Singleton::getInstance();
    singleton->showMessage();

    // Static class usage
    double sum = MathUtils::add(3.0, 4.0);
    double product = MathUtils::multiply(3.0, 4.0);
    cout << "Sum: " << sum << ", Product: " << product << endl;

    // Concrete class usage
    Circle circle(5.0, 1.0);
    circle.draw();
    cout << "Area: " << circle.area() << endl;

    Rectangle rectangle(4.0, 6.0, 2.0);
    rectangle.draw();
    cout << "Area: " << rectangle.area() << endl;

    // Interface class usage
    Triangle triangle(3.0, 4.0);
    triangle.draw();
    cout << "Area: " << triangle.area() << endl;

    // Nested class usage
    OuterClass::NestedClass nested;
    nested.display();

    // Final class usage
    FinalShape finalShape;
    finalShape.draw();

    // Limitations and constraints
    // AbstractShape cannot be instantiated
    // AbstractShape shape; // Error: cannot declare variable 'shape' to be of abstract type 'AbstractShape'

    // IShape cannot be instantiated
    // IShape shapeInterface; // Error: cannot declare variable 'shapeInterface' to be of abstract type 'IShape'

    // Singleton cannot be instantiated directly
    // Singleton anotherSingleton; // Error: 'Singleton::Singleton()' is private within this context

    // FinalShape cannot be subclassed
    // class DerivedFinalShape : public FinalShape {}; // Error: cannot derive from 'final' base 'FinalShape'

    // MathUtils cannot be instantiated
    // MathUtils mathUtils; // Error: cannot instantiate 'MathUtils' as it only contains static member functions
    
    // NestedClass can only be instantiated through OuterClass
    // OuterClass::NestedClass nested; // Correct way to instantiate a nested class

    return 0;
}


/*
OUTPUT
Singleton instance accessed
Sum: 7, Product: 12
Drawing a circle with radius: 5
Area: 78.5397
Drawing a rectangle with width: 4, height: 6 and color: 2
Area: 24
Drawing a triangle with base: 3 and height: 4
Area: 6
Inside Nested Class
Drawing a final shape
*/