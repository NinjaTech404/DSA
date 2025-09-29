cmake_minimum_required(VERSION 4.1.1)
project(
  MyDSAProject
  DESCRIPTION "A C++ Project for studying Data Structures and Algorithms. Why? cuz I hate myself!" 
  VERSION 1.0.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MAIN ${CMAKE_SOURCE_DIR}/src/main.cpp)
add_executable(MyRegrets ${MAIN})

include_directories(${CMAKE_SOURCE_DIR}/src)


