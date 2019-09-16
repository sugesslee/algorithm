cmake_minimum_required(VERSION 3.12)
project(temp)

set(CMAKE_CXX_STANDARD 14)

add_executable(temp main.cpp)
add_executable(ChickenProblemN ChickenProblem/ChickProblemN.cpp ChickenProblem/ChickProblemN.h)
add_executable(ChickenProblem ChickenProblem/ChickProblem.cpp ChickenProblem/ChickProblem.h)