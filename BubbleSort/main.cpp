//
// Created by red on 2020/2/5.
//

#include "../Sort/SortTestHelper.h"
#include "../Sort/Sort.h"

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generatorRandomArray(n, 0, n);


    SortTestHelper::testSort("insertion sort:generatorRandomArray", bubbleSort, arr, n);

    SortTestHelper::printArray(arr, n);
    delete[] arr;
}