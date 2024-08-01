#pragma once

#include <string>
#include <iostream>

#include "document.hpp"

class WordDocument : public Document {
public:
    WordDocument() {
        std::cout << "WordDocument: Constructor called." << std::endl;
    }

    ~WordDocument() override {
        std::cout << "WordDocument: Destructor called." << std::endl;
    }
    
    std::string getType() const override {
        return "Word Document";
    }
};