cmake_minimum_required(VERSION 3.2)
project(brainfuck)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(brainfuck ${SOURCE_FILES} AbstractMachine.cpp AbstractMachine.h Interpreter.cpp Interpreter.h)