#include <iostream>
using namespace std;


// Base class for shapes
class Shape {
public:
    // Pure Virtual Function
    // A pure virtual function is a function that has no implementation in the base class and must be overridden in derived classes.
    // t makes the base class abstract, meaning you cannot instantiate objects of the base class.
    // Example: The Shape class has a pure virtual function area() that must be implemented by derived classes like Circle and Rectangle.
    virtual double area() const = 0;

    // Virtual Function
    // A virtual function is a member function in a base class that you expect to override in derived classes.
    // It has a definition in the base class, which can be used by derived classes if they do not provide their own implementation.
    // The Shape class has a virtual function draw() that is overridden(optional) by derived classes like Circle and Rectangle.
    virtual void draw() const {
        cout << "Drawing shape" << endl;
    }

    // Virtual destructor
    virtual ~Shape() = default;
};

/*
When to Use Which One:
Virtual Function: Use when you want to provide a default behavior in the base class that can be optionally overridden by derived classes.
Pure Virtual Function: Use when you want to enforce that derived classes must provide their own implementation of the function.
*/


// Derived class for Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    // Implementing the pure virtual function area()
    double area() const override {
        return 3.14159 * radius * radius;
    }

    // Overriding the virtual function draw()
    void draw() const override {
        cout << "Drawing a circle with radius: " << radius << endl;
    }
};


// Derived class for Rectangle
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implementing the pure virtual function area()
    double area() const override {
        return width * height;
    }

    // Overriding the virtual function draw()
    void draw() const override {
        cout << "Drawing a rectangle with width: " << width << " and height: " << height << endl;
    }
};


int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->area() << endl;
        delete shapes[i];
    }

    return 0;
}


/*
OUTPUT
Drawing a circle with radius: 5
Area: 78.5397
Drawing a rectangle with width: 4 and height: 6
Area: 24
*/
