cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CONFIGURATION_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

project(Singleton)

#version number
set (Singleton_VERSION_MAJOR 1)
set (Singleton_VERSION_MINOR 0)

add_compile_options(
    -Wall
    -Werror # treat all warning as errors
    -Wextra # reasonable and standard
    -Wunused # warn on anything being unused
    -Wpedantic # warn if non-standard C++ is used
    -Wshadow # warn the user if a variable declaration shadows one form a parent context
    -Wnon-virtual-dtor # warn the user if a class with virtual 
                    # functions has a non-virtual destructor. This
                    # helps catch hard to track down memory errors
    -Wold-style-cast # warn for c-style casts
    -Wcast-align # warn for potential performance problem casts
    -Woverloaded-virtual # warn if you overload(not override) a virtual function
    -Wconversion # warn on type consversions taht may loose data
    -Wsign-conversion # warn on sign conversions
    -Wnull-dereference # warn if a null dereference is detected
    -Wdouble-promotion # warn of float is implicit promoted to double
    -Wformat=2 # warn on security issues around functions that format output (i.e printf)
    )

include_directories(include)

add_executable(
            a.out

            src/ThreadPoolManager.cpp
            src/Main.cpp
)
