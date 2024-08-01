#pragma once

#include <iostream>

#include "document.hpp"


class DocumentCreator {
public:
    DocumentCreator() {
        std::cout << "DocumentCreator: Constructor called." << std::endl;
    }

    virtual ~DocumentCreator() {
        std::cout << "DocumentCreator: Destructor called." << std::endl;
    }
    
    virtual Document* createDocument() const = 0;
};