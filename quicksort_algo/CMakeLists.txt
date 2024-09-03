cmake_minimum_required(VERSION 3.27.9)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main VERSION 0.1.0 LANGUAGES C CXX)

add_executable(main
${CMAKE_CURRENT_SOURCE_DIR}/src/quicksort_algo.cpp
    main.cpp
)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)