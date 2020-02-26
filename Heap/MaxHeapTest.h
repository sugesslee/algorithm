//
// Created by red on 2020/2/20.
//
#include <iostream>
#include "MaxHeap.h"
#include "../Sort/SortTestHelper.h"
#include "../Sort/MergeSort.h"
#include "../Sort/QuickSort.h"
#include "HeapSort.h"

using namespace std;

void MaxHeapTest() {
    /* // 测试最大堆创建
     MaxHeap<int> maxHeap = MaxHeap<int>(100);
     cout << maxHeap.size() << endl;


     MaxHeap<int> maxheap = MaxHeap<int>(100);

     srand(time(NULL));
     for (int i = 0; i < 50; i++)
         maxheap.insert(rand() % 100);

     maxheap.testPrint();*/

    /*MaxHeap<int> maxheap = MaxHeap<int>(100);

    srand(time(NULL));
    int n = 100;    // 随机生成n个元素放入最大堆中
    for (int i = 0; i < n; i++) {
        maxheap.insert(rand() % 100);
    }

    int *arr = new int[n];
    // 将maxheap中的数据逐渐使用extractMax取出来
    // 取出来的顺序应该是按照从大到小的顺序取出来的
    for (int i = 0; i < n; i++) {
        arr[i] = maxheap.extractMax();
        cout << arr[i] << " ";
    }
    cout << endl;

    // 确保arr数组是从大到小排列的
    for (int i = 1; i < n; i++)
        assert(arr[i - 1] >= arr[i]);

    delete[] arr;

    return 0;*/

    int n = 1000000;

    // 测试1 一般性测试
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int *arr1 = SortTestHelper::generatorRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyArray(arr1, n);
    int *arr3 = SortTestHelper::copyArray(arr1, n);
    int *arr4 = SortTestHelper::copyArray(arr1, n);
    int *arr5 = SortTestHelper::copyArray(arr1, n);
    int *arr6 = SortTestHelper::copyArray(arr1, n);
    int *arr7 = SortTestHelper::copyArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout << endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyArray(arr1, n);
    arr3 = SortTestHelper::copyArray(arr1, n);
    arr4 = SortTestHelper::copyArray(arr1, n);
    arr5 = SortTestHelper::copyArray(arr1, n);
    arr6 = SortTestHelper::copyArray(arr1, n);
    arr7 = SortTestHelper::copyArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout << endl;


    // 测试3 测试存在包含大量相同元素的数组
    cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
    arr1 = SortTestHelper::generatorRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyArray(arr1, n);
    arr3 = SortTestHelper::copyArray(arr1, n);
    arr4 = SortTestHelper::copyArray(arr1, n);
    arr5 = SortTestHelper::copyArray(arr1, n);
    arr6 = SortTestHelper::copyArray(arr1, n);
    arr7 = SortTestHelper::copyArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    // 这种情况下, 普通的QuickSort退化为O(n^2)的算法, 不做测试
    //SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", quickSort2Ways, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

}