cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Adapter)

include_directories(include)

add_executable(
            Adapter

            src/MallardDuck.cpp
            src/WildTurkey.cpp
            src/TurkeyAdapter.cpp
            src/DuckTestDrive.cpp
)
