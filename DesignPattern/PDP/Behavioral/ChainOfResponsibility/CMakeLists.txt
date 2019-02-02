cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)


project(ChainOfResponsibility)

include_directories(include)

add_executable(
            a.out

            src/Logger.cpp
            src/StdoutLogger.cpp
            src/StderrLogger.cpp
            src/EmailLogger.cpp
            src/ChainOfResponsibilityExample.cpp
)
