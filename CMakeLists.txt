cmake_minimum_required(VERSION 3.20)
project(mechanics_cpp)

set(CMAKE_CXX_STANDARD 20)

find_package(GSL REQUIRED)

add_subdirectory(src)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "Building Tests")
    enable_testing()
    add_subdirectory(tests)
endif ()