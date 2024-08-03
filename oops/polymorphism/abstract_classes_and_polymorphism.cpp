#include <iostream>
#include <vector>
using namespace std;

// Abstract class: Shape
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double area() const = 0; // No implementation; derived classes must implement this

    virtual void draw() const {
        cout << "Drawing a generic shape." << endl;
    }

    virtual ~Shape() = default;
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        cout << "Drawing a circle with radius: " << radius << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height; 
    }

    void draw() const override {
        cout << "Drawing a rectangle with width: " << width << " and height: " << height << endl;
    }
};

// Function to demonstrate polymorphism
void drawShapes(const vector<Shape*>& shapes) {
    for (const auto& shape : shapes) {
        shape->draw(); // Calls the appropriate draw method based on actual object type
        cout << "Area: " << shape->area() << endl;
    }
}

// Main function
int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));

    drawShapes(shapes);

    // Clean up allocated memory
    for (auto shape : shapes) {
        delete shape;
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