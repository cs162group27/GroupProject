cmake_minimum_required(VERSION 3.13)
project(group_project)

set(CMAKE_CXX_STANDARD 11)

add_executable(group_project main.cpp menu.cpp menu.hpp inputValidation.cpp inputValidation.hpp Board.cpp Board.hpp Critter.cpp Critter.hpp Ant.cpp Ant.hpp Doodlebug.hpp Doodlebug.cpp)