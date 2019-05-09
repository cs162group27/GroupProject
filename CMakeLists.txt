cmake_minimum_required(VERSION 3.13)
project(Doodle_Bug)

set(CMAKE_CXX_STANDARD 11)

add_executable(Doodle_Bug main.cpp Ant.cpp Critter.cpp Doodlebug.cpp inputValidation.cpp menu.cpp Board.cpp)