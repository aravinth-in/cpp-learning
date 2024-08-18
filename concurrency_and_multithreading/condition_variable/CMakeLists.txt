cmake_minimum_required(VERSION 3.10)

set(SOURCE_FILES
    condition_variable_1.cpp
    condition_variable_2.cpp
    condition_variable_3.cpp
    producer_consumer.cpp
)

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()