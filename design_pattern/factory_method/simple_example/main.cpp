#include <iostream>

#include "pdf_document_creator.hpp"
#include "word_document_creator.hpp"

void createAndPrintDocument(const DocumentCreator& creator) {
    Document* doc = creator.createDocument();
    std::cout << "createAndPrintDocument: Created a " << doc->getType() << std::endl;
    delete doc;
}

int main() {
    PDFDocumentCreator pdfCreator;
    WordDocumentCreator wordCreator;

    createAndPrintDocument(pdfCreator);
    createAndPrintDocument(wordCreator);

    return 0;
}

/*
OUTPUT
PDFDocumentCreator: Creating a PDF document.
createAndPrintDocument: Created a PDF Document
WordDocumentCreator: Creating a Word document.
createAndPrintDocument: Created a Word Document
*/


/*
OUTPUT (with contructor and destructor call statements)
DocumentCreator: Constructor called.
PDFDocumentCreator: Constructor called.
DocumentCreator: Constructor called.
WordDocumentCreator: Constructor called.
PDFDocumentCreator: Creating a PDF document.
Document: Constructor called.
PDFDocument: Constructor called.
createAndPrintDocument: Created a PDF Document
PDFDocument: Destructor called.
Document: Destructor called.
WordDocumentCreator: Creating a Word document.
Document: Constructor called.
WordDocument: Constructor called.
createAndPrintDocument: Created a Word Document
WordDocument: Destructor called.
Document: Destructor called.
WordDocumentCreator: Destructor called.
DocumentCreator: Destructor called.
PDFDocumentCreator: Destructor called.
DocumentCreator: Destructor called.*/