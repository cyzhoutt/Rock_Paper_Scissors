cmake_minimum_required(VERSION 3.15)
project(rps)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_executable(RockPaperScissors main.cpp rps.cpp)
