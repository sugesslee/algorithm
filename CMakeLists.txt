cmake_minimum_required(VERSION 3.12)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChickenProblemN ChickenProblem/ChickProblemN.cpp ChickenProblem/ChickProblemN.h ChickenProblem/ChickProblem.cpp ChickenProblem/ChickProblem.h)
add_executable(test test/test.c)
add_executable(SelectionSort SelectionSort/main.cpp SelectionSort/Student.h SelectionSort/SortTestHelper.h)
add_executable(InsertionSort InsertionSort/main.cpp InsertionSort/Sort.h)