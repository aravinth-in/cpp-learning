#pragma once
#include <string>
#include <iostream>

class Document {
public:
    Document() {
        std::cout << "Document: Constructor called." << std::endl;
    }

    virtual ~Document() {
        std::cout << "Document: Destructor called." << std::endl;
    }
    
    virtual std::string getType() const = 0;
};