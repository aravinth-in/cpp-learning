cmake_minimum_required(VERSION 3.10)

set(SOURCE_FILES
    atomic_flag_spinlock.cpp
    atomic_operation.cpp
    atomic_increment.cpp
    atomic_memory_order.cpp
)

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()