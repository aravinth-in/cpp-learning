cmake_minimum_required(VERSION 3.10)

set(SOURCE_FILES
    callable_objects.cpp
    callback.cpp
    constant_and_pointers.cpp
    copy_and_move_semantics.cpp
    friend_class_and_friend_function.cpp
    lambda_function.cpp
    lambda_function_1.cpp
    lvalue_and_rvalue.cpp
    virtual_and_pure_virtual_function.cpp
)

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()

add_subdirectory(static)