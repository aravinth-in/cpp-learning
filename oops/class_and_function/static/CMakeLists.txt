cmake_minimum_required(VERSION 3.10)

set(HEADER_FILES
    static_demo_class.hpp
)

set(SOURCE_FILES
    file_1.cpp
    file_2.cpp
    static.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(static_demo 
    file_1.cpp
    file_2.cpp)

add_executable(static static.cpp)

target_include_directories(static_demo 
   PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)