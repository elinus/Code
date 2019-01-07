cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Strategy)

include_directories(include)

add_executable(
            Strategy

            src/FlyWithWings.cpp
            src/FlyNoWay.cpp
            src/FlyRocketPowered.cpp
            src/Quack.cpp
            src/MuteQuack.cpp
            src/Squeak.cpp
            src/Duck.cpp
            src/MallardDuck.cpp
            src/RedheadDuck.cpp
            src/RubberDuck.cpp
            src/DecoyDuck.cpp
            src/ModelDuck.cpp
            src/MiniDuckSimulator.cpp
)
