cmake_minimum_required(VERSION 3.15)
project(fuel_calculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(fuel_calculator 
    src/main.cpp
)