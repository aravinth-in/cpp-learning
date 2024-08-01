#pragma once 

#include <iostream>

#include "document_creator.hpp"
#include "word_document.hpp"


class WordDocumentCreator : public DocumentCreator {
public:
    WordDocumentCreator() {
        std::cout << "WordDocumentCreator: Constructor called." << std::endl;
    }

    ~WordDocumentCreator() override {
        std::cout << "WordDocumentCreator: Destructor called." << std::endl;
    }

    Document* createDocument() const override {
        std::cout << "WordDocumentCreator: Creating a Word document." << std::endl;
        return new WordDocument();
    }
};