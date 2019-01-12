cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Facade)

include_directories(include)

add_executable(
            Facade

            src/Amplifier.cpp	
            src/CdPlayer.cpp	
            src/DvdPlayer.cpp	
            src/PopcornPopper.cpp	
            src/Projector.cpp	
            src/Screen.cpp	
            src/TheaterLights.cpp	
            src/Tuner.cpp
            src/HomeTheaterFacade.cpp
            src/HomeTheaterTestDrive.cpp
)

