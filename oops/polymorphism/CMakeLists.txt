cmake_minimum_required(VERSION 3.10)

set(SOURCE_FILES
    abstract_classes_and_polymorphism.cpp
    compiletime_polymorphism.cpp
    runtime_polymorphism.cpp
)

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()