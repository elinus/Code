cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 11)

project (sqlite_db_client)

add_executable(a.out src/Main.cpp)

include_directories (include src libs/sqlite/bin/include)
add_library (sqlite SHARED IMPORTED)
set_property (TARGET sqlite PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/sqlite/bin/libsqlite.so)
target_link_libraries (a.out sqlite pthread ${CMAKE_DL_LIBS})

