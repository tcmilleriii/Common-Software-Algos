cmake_minimum_required(VERSION 3.27.9)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(depth_first VERSION 0.1.0 LANGUAGES C CXX)

add_executable(depth_first 
    depth_first.cpp
    ../src/graphTraversalHelper.cpp
)
target_include_directories(depth_first PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)