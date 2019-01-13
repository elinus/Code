cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Command)

include_directories(include)

add_executable(
            Command

            src/Light.cpp	
            src/LightOnCommand.cpp	
            src/LightOffCommand.cpp
            src/GarageDoor.cpp
            src/GarageDoorDownCommand.cpp
            src/GarageDoorUpCommand.cpp
            src/SimpleRemoteControl.cpp	
            src/RemoteControlTest.cpp	
)

