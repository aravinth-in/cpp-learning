cmake_minimum_required(VERSION 3.10)

# Set the project name
project(cpp-learning)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(concurrency_and_multithreading)
add_subdirectory(design_pattern)
add_subdirectory(oops)
add_subdirectory(principles)
add_subdirectory(smart_pointers)
add_subdirectory(template)
