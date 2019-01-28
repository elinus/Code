cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wunused")

project(ChainOfResponsibility)

include_directories(include/ChainOfResponsibility)

add_executable(
            a.out

            src/Logger.cpp
            src/StdoutLogger.cpp
            src/StderrLogger.cpp
            src/EmailLogger.cpp
            src/ChainOfResponsibilityExample.cpp
)
