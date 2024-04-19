cmake_minimum_required(VERSION 3.27)
project(tetris_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(tetris_cpp
        src/main.cpp
        src/lib/cpp/Tauler.cpp
        src/lib/headers/Tauler.h
        src/lib/cpp/Joc.cpp
        src/lib/headers/Joc.h
        src/lib/cpp/Figura.cpp
        src/lib/headers/Figura.h)
