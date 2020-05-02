cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wunused")

project(Strategy)

include_directories(include/Strategy)

add_executable(
            a.out

            src/QuickSort.cpp
            src/BubbleSort.cpp
            src/Sorter.cpp
            src/MySorter.cpp
            src/StrategyTest.cpp
)
