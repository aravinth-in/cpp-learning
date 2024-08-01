#pragma once

#include <string>
#include <iostream>

#include "document.hpp"

class PDFDocument : public Document {
public:
    PDFDocument() {
        std::cout << "PDFDocument: Constructor called." << std::endl;
    }

    ~PDFDocument() override {
        std::cout << "PDFDocument: Destructor called." << std::endl;
    }
    
    std::string getType() const override {
        return "PDF Document";
    }
};