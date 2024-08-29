cmake_minimum_required(VERSION 3.27.9)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(dijkstras_method VERSION 0.1.0 LANGUAGES C CXX)

add_executable(dijkstras_method 
    dijkstras_method.cpp
    ../src/graphTraversalHelper.cpp
)
target_include_directories(dijkstras_method PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)