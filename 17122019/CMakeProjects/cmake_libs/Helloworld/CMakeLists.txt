cmake_minimum_required(VERSION 3.0)

project(Helloworld)

include_directories(include)

add_library(
        Helloworld
        SHARED
        src/Helloworld.cpp
)
