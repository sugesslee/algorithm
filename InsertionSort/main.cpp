//
// Created by red on 2020/2/4.
//

#include "../Sort/SortTestHelper.h"
#include <algorithm>
#include "../Sort/Sort.h"

using namespace std;

int main() {
    int n = 10000;
    int *arr1 = SortTestHelper::generatorRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyArray(arr1, n);


    SortTestHelper::testSort("insertion sort:generatorRandomArray", insertionSort, arr1, n);
    SortTestHelper::testSort("selection sort:generatorRandomArray", selectionSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    int *arr3 = SortTestHelper::generateNearlyOrderedArray(n, 200);
    int *arr4 = SortTestHelper::copyArray(arr1, n);


    SortTestHelper::testSort("insertion sort:generateNearlyOrderedArray", insertionSort, arr3, n);
    SortTestHelper::testSort("selection sort:generateNearlyOrderedArray", selectionSort, arr4, n);

    delete[] arr3;
    delete[] arr4;
    return 0;
}
