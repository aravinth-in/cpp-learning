cmake_minimum_required(VERSION 3.10)

# Set the project name
project(cpp-learning)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Function to add executables for each source file
function(add_executables_from_directory dir)
    file(GLOB_RECURSE SOURCES "${dir}/*.cpp")
    foreach(SOURCE ${SOURCES})
        if(NOT ${SOURCE} MATCHES "oops/class_and_function/static/file_2.cpp" AND
            NOT ${SOURCE} MATCHES "oops/class_and_function/static/file_1.cpp")
            get_filename_component(EXE_NAME ${SOURCE} NAME_WE)
            add_executable(${EXE_NAME} ${SOURCE})
        endif()
    endforeach()
endfunction()

# Add executables for each directory
add_executables_from_directory("${CMAKE_SOURCE_DIR}/oops")
add_executables_from_directory("${CMAKE_SOURCE_DIR}/smart_pointers")
# Add more directories as needed