cmake_minimum_required(VERSION 3.6)
project(CityData)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c io.c computations.c)
add_executable(CityData ${SOURCE_FILES})