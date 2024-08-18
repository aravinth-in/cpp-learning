cmake_minimum_required(VERSION 3.10)

set(SOURCE_FILES
    mutex_types.cpp
    mutex_locking_strategies_1.cpp
    mutex_locking_strategies_2.cpp
)

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
endforeach()
