cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Observer)

include_directories(include)

add_executable(
            Observer

            src/WeatherData.cpp
            src/CurrentConditionsDisplay.cpp
            src/WeatherStation.cpp
)
