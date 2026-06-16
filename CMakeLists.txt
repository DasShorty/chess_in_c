cmake_minimum_required(VERSION 4.2)
project(chess_in_c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(chess_in_c
        main.c)
