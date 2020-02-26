cmake_minimum_required(VERSION 3.12)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChickenProblemN ChickenProblem/ChickProblemN.cpp ChickenProblem/ChickProblemN.h ChickenProblem/ChickProblem.cpp ChickenProblem/ChickProblem.h)
add_executable(test test/test.cpp)
add_executable(SelectionSort SelectionSort/main.cpp SelectionSort/Student.h Sort/SortTestHelper.h)
add_executable(InsertionSort InsertionSort/main.cpp Sort/Sort.h Sort/MergeSort.h Sort/QuickSort.h)
add_executable(Bubble BubbleSort/main.cpp)
add_executable(MergeSort MergeSort/main.cpp)
add_executable(QuickSort QuickSort/main.cpp)
add_executable(Heap Heap/MaxHeap.h Heap/MaxHeapTest.h Heap/HeapSort.h Heap/IndexMaxHeap.h Heap/IndexMaxHeapTest.h Heap/main.cpp Heap/IndexMaxHeapTest1.h)