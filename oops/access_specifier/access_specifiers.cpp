#include <iostream>
#include <string>


class Person {
protected:
    std::string name;

public:
    int age;

    Person(const std::string& name, int age)
        : name(name), age(age) {}
};


class Employee : protected Person {
private:
    std::string employeeID;

public:
    Employee(const std::string& name, int age, const std::string& employeeID)
        : Person(name, age), employeeID(employeeID) {}

    void displayEmployeeDetails() const {
        // Can access 'name' and 'age' because they are protected members of Employee
        std::cout << "Employee Name: " << name << ", Age: " << age << ", Employee ID: " << employeeID << std::endl;
    }
};


class PublicEmployee : public Employee {
public:
    PublicEmployee(const std::string& name, int age, const std::string& employeeID)
        : Employee(name, age, employeeID) {}

    void displayPublicEmployeeDetails() const {
        // Can access 'name' and 'age' because they are protected in Employee
        std::cout << "Public Employee Name: " << name << ", Age: " << age << std::endl; // Error
    }
};


class ProtectedEmployee : protected Employee {
public:
    ProtectedEmployee(const std::string& name, int age, const std::string& employeeID)
        : Employee(name, age, employeeID) {}

    void displayProtectedEmployeeDetails() const {
        // Can access 'name' and 'age' because they are protected in Employee
        std::cout << "Protected Employee Name: " << name << ", Age: " << age << std::endl; // Error
    }
};


class PrivateEmployee : private Employee {
public:
    PrivateEmployee(const std::string& name, int age, const std::string& employeeID)
        : Employee(name, age, employeeID) {}

    void displayPrivateEmployeeDetails() const {
        // Can access 'name' and 'age' because they are private in PrivateEmployee
        std::cout << "Private Employee Name: " << name << ", Age: " << age << std::endl; // Error
    }
};


// Example of a class inheriting from PrivateEmployee
class DerivedFromPrivateEmployee : public PrivateEmployee {
public:
    DerivedFromPrivateEmployee(const std::string& name, int age, const std::string& employeeID)
        : PrivateEmployee(name, age, employeeID) {}

    void displayDerivedDetails() const {
        // Cannot access 'name' and 'age' because they are private in PrivateEmployee
        // std::cout << "Derived Name: " << name << ", Age: " << age << std::endl; // This would cause a compilation error
    }
};


int main() {
    Employee employee("Jane Smith", 28, "E12345");
    employee.displayEmployeeDetails();

    PublicEmployee publicEmployee("John Doe", 30, "E54321");
    publicEmployee.displayPublicEmployeeDetails();
    publicEmployee.displayEmployeeDetails(); // Accessible because displayEmployeeDetails() is public in Employee

    ProtectedEmployee protectedEmployee("Alice Johnson", 35, "E67890");
    protectedEmployee.displayProtectedEmployeeDetails();
    // protectedEmployee.displayEmployeeDetails(); // Not accessible because displayEmployeeDetails() is protected in ProtectedEmployee

    PrivateEmployee privateEmployee("Bob Brown", 40, "E98765");
    privateEmployee.displayPrivateEmployeeDetails();
    // privateEmployee.displayEmployeeDetails(); // Not accessible because displayEmployeeDetails() is private in PrivateEmployee

    DerivedFromPrivateEmployee derivedFromPrivateEmployee("Bob Brown", 40, "E98765");
    derivedFromPrivateEmployee.displayPrivateEmployeeDetails(); 
    // derivedFromPrivateEmployee.displayEmployeeDetails(); // Not accessible because displayEmployeeDetails() is private in DerivedFromPrivateEmployee
    return 0;
}


/*
Access Specifiers:
Access specifiers define the accessibility of members (attributes and methods) of a class. There are three primary access specifiers in C++:

Public:
Members declared as public are accessible from outside the class.
They can be accessed by any other code that has visibility of the class object.

Protected:
Members declared as protected are accessible within the class itself and by derived classes.
They are not accessible from outside the class, except by derived classes.

Private:
Members declared as private are only accessible within the class itself.
They cannot be accessed directly by derived classes or any other code outside the class.
*/


/*
Inheritance and Access Specifiers:
When a class inherits from another class, the access specifier used for inheritance affects the accessibility of the base class members in the derived class.

Public Inheritance:
Public members of the base class remain public in the derived class.
Protected members of the base class remain protected in the derived class.
Private members of the base class remain inaccessible to the derived class.

Protected Inheritance:
Public members of the base class become protected in the derived class.
Protected members of the base class remain protected in the derived class.
Private members of the base class remain inaccessible to the derived class.

Private Inheritance:
Public members of the base class become private in the derived class.
Protected members of the base class become private in the derived class.
Private members of the base class remain inaccessible to the derived class.

Summary: 
Public: Accessible from anywhere.
Protected: Accessible within the class and derived classes.
Private: Accessible only within the class.
Inheritance: The type of inheritance (public, protected, private) affects the accessibility of base class members in the derived class.
*/


/*
Protected Inheritance: When Employee inherits from Person using protected inheritance, the name and age members of Person become protected members of Employee.
Public Inheritance: When PublicEmployee inherits from Employee using public inheritance, the protected members of Employee (name and age) remain protected in PublicEmployee.
Protected Inheritance: When ProtectedEmployee inherits from Employee using protected inheritance, the protected members of Employee (name and age) remain protected in ProtectedEmployee.
Private Inheritance: When PrivateEmployee inherits from Employee using private inheritance, the protected members of Employee (name and age) become private in PrivateEmployee.
Subsequent Inheritance from PrivateEmployee: Any class that inherits from PrivateEmployee, regardless of the inheritance type (public, protected, or private), will not have access 
to name and age because they are private in PrivateEmployee.
*/