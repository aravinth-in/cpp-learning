#include <iostream>

class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class PublicDerived : public Base {
    // publicVar is public
    // protectedVar is protected
    // privateVar is not accessible
public:
    void display() {
        std::cout << "publicVar: " << publicVar << std::endl;
        std::cout << "protectedVar: " << protectedVar << std::endl;
        // std::cout << "privateVar: " << privateVar << std::endl; // Not accessible
    }
};

class ProtectedDerived : protected Base {
    // publicVar is protected
    // protectedVar is protected
    // privateVar is not accessible
public:
    void display() {
        std::cout << "publicVar: " << publicVar << std::endl;
        std::cout << "protectedVar: " << protectedVar << std::endl;
        // std::cout << "privateVar: " << privateVar << std::endl; // Not accessible
    }
};

class PrivateDerived : private Base {
    // publicVar is private
    // protectedVar is private
    // privateVar is not accessible
public:
    void display() {
        std::cout << "publicVar: " << publicVar << std::endl;
        std::cout << "protectedVar: " << protectedVar << std::endl;
        // std::cout << "privateVar: " << privateVar << std::endl; // Not accessible
    }
};

class PrivateProtectedDerived : private ProtectedDerived {
    // publicVar is protected
    // protectedVar is protected
public:
    void display() {
        std::cout << "publicVar: " << publicVar << std::endl;
        std::cout << "protectedVar: " << protectedVar << std::endl;
    }
};

class Public2Derived : public PublicDerived {
    // publicVar is public
    // protectedVar is protected
public:
    void display() {
        std::cout << "publicVar: " << publicVar << std::endl;
        std::cout << "protectedVar: " << protectedVar << std::endl;
    }
};


// Detailed Analysis of Inheritance and Access Specifiers in Derived Classes:
class PrivatePublic2Derived : private Public2Derived {
    // publicVar is private
    // protectedVar is private
    // data is public
public:
    int data;
    void display() {
        std::cout << "publicVar: " << publicVar << std::endl; // Not accessible
        std::cout << "protectedVar: " << protectedVar << std::endl; // Not accessible
    }
};

class Private2Public2Derived : private PrivatePublic2Derived {
    // publicVar is private
    // protectedVar is private
    // data is private
public:
    void display() {
        std::cout << "data: " << data << std::endl; 
        // std::cout << "publicVar: " << publicVar << std::endl; // Not accessible
        // std::cout << "protectedVar: " << protectedVar << std::endl; // Not accessible
    }
};

class Private3Public2Derived : private Private2Public2Derived {
// data is private, so it is not accessible in this class
public:
    void display() {
        // std::cout << "data: " << data << std::endl; // Not accessible
    }
};

class ProtectedPrivate2Public2Derived : protected PrivatePublic2Derived {
public:
    void display() {
        std::cout << "data: " << data << std::endl; 
    }
};

class Protected2Private2Public2Derived : protected ProtectedPrivate2Public2Derived {
// data is protected, so it is accessible in this class
public:
    void display() {
        std::cout << "data: " << data << std::endl;
    }
};

int main() {
    PublicDerived publicDerived;
    publicDerived.display();

    ProtectedDerived protectedDerived;
    protectedDerived.display();

    PrivateDerived privateDerived;
    privateDerived.display();

    Public2Derived public2Derived;
    public2Derived.display();

    PrivateProtectedDerived privateProtectedDerived;
    privateProtectedDerived.display();

    PrivatePublic2Derived privatePublic2Derived;
    privatePublic2Derived.display();

    Private2Public2Derived private2Public2Derived;
    private2Public2Derived.display();

    Private3Public2Derived private3Public2Derived;
    private3Public2Derived.display();

    ProtectedPrivate2Public2Derived protectedPrivate2Public2Derived;
    protectedPrivate2Public2Derived.display();

    Protected2Private2Public2Derived protected2Private2Public2Derived;
    protected2Private2Public2Derived.display();

    return 0;
}