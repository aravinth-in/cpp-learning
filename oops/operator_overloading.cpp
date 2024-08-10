#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator
    // Current Object (this): When you call c1 + c2, c1 is the current object (this), 
    // and its members can be accessed directly using real and imag.
    // Other Object (other): c2 is passed as the other parameter to the function. 
    // Its members are accessed using other.real and other.imag.
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload == operator
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // Overload != operator
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Overload << operator for output
    // Declared as a friend to modify private members c.real and c.imag of Complex class.
    // For more details on why we return std::ostream&, please refer to osstream_and_isstream.md file.
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    // Overload >> operator for input
    // Declared as a friend to modify private members c.real and c.imag of Complex class.
    friend std::istream& operator>>(std::istream& is, Complex& c) {
        std::cout << "Enter real part: ";
        is >> c.real;
        std::cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};


int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3;

    std::cout << "Enter a complex number (c3):\n";
    std::cin >> c3;

    std::cout << "c1: " << c1 << "\n";
    std::cout << "c2: " << c2 << "\n";
    std::cout << "c3: " << c3 << "\n";

    std::cout << "c1 + c2 = " << c1 + c2 << "\n";
    std::cout << "c1 - c2 = " << c1 - c2 << "\n";

    std::cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << "\n";
    std::cout << "c1 != c2: " << (c1 != c2 ? "true" : "false") << "\n";

    return 0;
}