#pragma once 

#include <iostream>

#include "document_creator.hpp"
#include "pdf_document.hpp"


class PDFDocumentCreator : public DocumentCreator {
public:
    PDFDocumentCreator() {
        std::cout << "PDFDocumentCreator: Constructor called." << std::endl;
    }

    ~PDFDocumentCreator() override {
        std::cout << "PDFDocumentCreator: Destructor called." << std::endl;
    }
    
    Document* createDocument() const override {
        std::cout << "PDFDocumentCreator: Creating a PDF document." << std::endl;
        return new PDFDocument();
    }
};