cmake_minimum_required(VERSION 3.28)
project(clion)

set(CMAKE_CXX_STANDARD 26)

add_executable(clion main.cpp
        game.cpp
        game.h)
