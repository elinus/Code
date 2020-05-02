cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("Builder Pattern")

#include_directories(include)

file(GLOB builder_src
    "*.h"
    "*.cpp"
    )

add_executable(
    a.out
    ${builder_src}
    )


