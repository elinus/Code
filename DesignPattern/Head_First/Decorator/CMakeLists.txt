cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Decorator)

include_directories(include)

add_executable(
            Decorator

            src/Beverage.cpp
            src/Espresso.cpp
            src/HouseBlend.cpp
            src/DarkRoast.cpp
            src/Decaf.cpp
            src/Mocha.cpp
            src/Whip.cpp
            src/Milk.cpp
            src/Soy.cpp
            src/StarbuzzCoffee.cpp
)
