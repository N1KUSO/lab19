cmake_minimum_required(VERSION 3.26)
project(lab14 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab14 main.c
        libs/data_structures/vector/vector.h
        libs/data_structures/vector/vectorVoid.h)
