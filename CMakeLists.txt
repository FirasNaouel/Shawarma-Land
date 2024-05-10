cmake_minimum_required(VERSION 3.28)
project(clion)

set(CMAKE_CXX_STANDARD 26)

add_executable(clion main.cpp
        game.cpp
        game.h
        program.cpp
        coa.h
        coa.cpp
        program.h
        player.h
        player.cpp
        timer.cpp
        timer.h)
