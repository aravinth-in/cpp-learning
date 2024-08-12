#include <iostream>
#include <cstring>

// String class demonstrating copy and move semantics
class String
{
public:
    char *data;
    size_t length;

    // Default constructor
    String(const char *str = "")
    {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Copy constructor: Called during initialization with another object.
    String(const String &other) : length(other.length), data(new char[other.length + 1])
    {
        std::strcpy(data, other.data);
        std::cout << "Copy constructor called" << std::endl;
    }

    // Move constructor: Called during initialization with an rvalue reference.
    String(String &&other) noexcept : data(other.data), length(other.length)
    {
        other.data = nullptr;
        other.length = 0;
        std::cout << "Move constructor called" << std::endl;
    }

    // Copy assignment operator: Called when assigning an existing object to another existing object.
    String& operator=(const String &other)
    {
        if (this == &other)
            return *this; // Handle self-assignment

        delete[] data; // Free existing resource

        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        std::cout << "Copy assignment operator called" << std::endl;

        return *this;
    }

    // Move assignment operator: Called when assigning an existing object to an rvalue reference.
    String& operator=(String &&other) noexcept
    {
        if (this == &other)
            return *this; // Handle self-assignment

        delete[] data; // Free existing resource

        data = other.data;
        length = other.length;

        other.data = nullptr;
        other.length = 0;
        std::cout << "Move assignment operator called" << std::endl;

        return *this;
    }

    ~String()
    {
        delete[] data;
    }

    void print() const
    {
        if (data)
        {
            std::cout << data << std::endl;
        }
        else
        {
            std::cout << "String is empty or moved" << std::endl;
        }
    }
};


int main()
{
    String str1("Hello, World!"); // Default constructor
    std::cout << "str1: ";
    str1.print();

    String str2 = str1; // Copy constructor, same like String str2(str1);
    std::cout << "str2 (after copy): ";
    str2.print();

    String str3 = std::move(str1); // Move constructor
    std::cout << "str3 (after move): ";
    str3.print();

    std::cout << "str1 (after move): ";
    str1.print(); // str1 is now in a valid but unspecified state

    String str4("Goodbye!"); // Default constructor
    std::cout << "str4: ";
    str4.print();

    str4 = str2; // Copy assignment operator
    std::cout << "str4 (after copy assignment): ";
    str4.print();

    str4 = std::move(str3); // Move assignment operator
    std::cout << "str4 (after move assignment): ";
    str4.print();

    std::cout << "str3 (after move assignment): ";
    str3.print(); // str3 is now in a valid but unspecified state

    return 0;
}


/*
OUTPUT
str1: Hello, World!
Copy constructor called
str2 (after copy): Hello, World!
Move constructor called
str3 (after move): Hello, World!
str1 (after move): String is empty or moved
str4: Goodbye!
Copy assignment operator called
str4 (after copy assignment): Hello, World!
Move assignment operator called
str4 (after move assignment): Hello, World!
str3 (after move assignment): String is empty or moved
*/