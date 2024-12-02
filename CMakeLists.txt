cmake_minimum_required(VERSION 3.30)
project(AoC2024)

set(CMAKE_CXX_STANDARD 20)

add_executable(main_program main.cpp
        Day02/part1.cpp
        Day02/part2.cpp)
add_executable(part1_program Day01/part1.cpp)
add_executable(part2_program Day01/part2.cpp)
