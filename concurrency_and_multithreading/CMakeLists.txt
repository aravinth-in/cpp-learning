cmake_minimum_required(VERSION 3.10)

set(SOURCE_FILES
    thread_synchronization.cpp
)

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()

add_subdirectory(atomic)
add_subdirectory(condition_variable)
add_subdirectory(deadlock)
add_subdirectory(mutex)