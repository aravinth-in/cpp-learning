cmake_minimum_required(VERSION 3.10)

set(HEADER_FILES
    configuration_manager.hpp
)

set(SOURCE_FILES
    configuration_manager.hpp
    main.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(singleton_executable ${HEADER_FILES} ${SOURCE_FILES})

set(SINGLETON_INDEPENDENT_EXECUTABLE
    singleton_1.cpp
    singleton_2.cpp
)

foreach(SINGLETON_INDEPENDENT_EXECUTABLE ${SINGLETON_INDEPENDENT_EXECUTABLE})
    get_filename_component(EXECUTABLE_NAME ${SINGLETON_INDEPENDENT_EXECUTABLE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SINGLETON_INDEPENDENT_EXECUTABLE})
endforeach()
