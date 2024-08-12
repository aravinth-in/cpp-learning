cmake_minimum_required(VERSION 3.10)

set(HEADER_FILES
    document_creator.hpp
    document.hpp
    pdf_document_creator.hpp
    pdf_document.hpp
    word_document_creator.hpp
    word_document.hpp
)

set(SOURCE_FILES
    main.cpp
)

add_executable(factory_method_executable ${HEADER_FILES} ${SOURCE_FILES})