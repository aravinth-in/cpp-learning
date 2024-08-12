cmake_minimum_required(VERSION 3.10)

set(SOURCE_FILES
    smart_pointer.cpp
    smart_pointer_1.cpp
    smart_pointer_2.cpp
)

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()
