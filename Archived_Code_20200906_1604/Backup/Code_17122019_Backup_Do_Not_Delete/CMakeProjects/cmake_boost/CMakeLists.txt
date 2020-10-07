cmake_minimum_required(VERSION 3.0)

project(cmake_boost)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CONFIGURATION_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.65.1 REQUIRED COMPONENTS system)

if (Boost_Found)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(
    a.out
    BoostTest.cpp
)
target_link_libraries(a.out ${Boost_LIBRARIES})
