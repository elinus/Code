cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11" -pthread)

project (sqlite VERSION 1.0.0 DESCRIPTION "Sqlite3")

include_directories (include)
add_library (sqlite SHARED src/sqlite3.c)

#set_target_properties (sqlite PROPERTIES VERSION ${PROJECT_VERSION})
#set_target_properties (sqlite PROPERTIES PUBLIC_HEADER include/sqlite3.h)
#target_include_directories (sqlite PRIVATE include)

