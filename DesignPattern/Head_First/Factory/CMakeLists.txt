cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Factory)

include_directories(include)

add_executable(
        a.out

        src/Pizza.cpp
        src/CheesePizza.cpp
        src/ClamPizza.cpp
        src/PepperoniPizza.cpp
        src/VeggiePizza.cpp
        src/PizzaStore.cpp
        src/SimplePizzaFactory.cpp
        src/PizzaTestDrive.cpp
)
