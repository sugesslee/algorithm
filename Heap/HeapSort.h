//
// Created by red on 2020/2/24.
//

#ifndef ALGORITHM_HEAPSORT_H
#define ALGORITHM_HEAPSORT_H

#include <iostream>
#include <algorithm>
#include "MaxHeap.h"

using namespace std;

// heapSort1 将所有元素依次添加到堆，再将元素依次从堆取出，即完成排序
// 无论是创建堆还是从堆中取元素的过程，时间复杂度都是O(n logn)
// 整个堆排序的时间复杂度是O(n log n)
template<typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(n);

    for (int i = 0; i < n; ++i) {
        maxHeap.insert(arr[i]);
    }
    for (int j = n - 1; j >= 0; --j) {
        arr[j] = maxHeap.extractMax();
    }
}

// 使用heapify过程创建堆
// 创建堆的时间复杂度为O(n)，将所有元素依次从堆中取出来，时间复杂度为O(nlogn)
// 排序时间依然为O(nlogn)
template<typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = maxHeap.extractMax();
    }
}
// 优化的shiftDown过程, 使用赋值的方式取代不断的swap,
// 该优化思想和我们之前对插入排序进行优化的思路是一致的，取消swap()操作改为赋值操作
template<typename T>
void __shiftDown2(T arr[], int n, int k) {

    T e = arr[k];
    while (2 * k + 1 < n) {
        int j = 2 * k + 1;
        if (j + 1 < n && arr[j + 1] > arr[j])
            j += 1;

        if (e >= arr[j]) break;

        arr[k] = arr[j];
        k = j;
    }

    arr[k] = e;
}
// 不使用一个额外的最大堆, 直接在原数组上进行原地的堆排序
template<typename T>
void heapSort(T arr[], int n){

    // 注意，此时我们的堆是从0开始索引的
    // 从(最后一个元素的索引-1)/2开始
    // 最后一个元素的索引 = n-1
    for( int i = (n-1-1)/2 ; i >= 0 ; i -- )
        __shiftDown2(arr, n, i);

    for( int i = n-1; i > 0 ; i-- ){
        swap( arr[0] , arr[i] );
        __shiftDown2(arr, i, 0);
    }
}
#endif //ALGORITHM_HEAPSORT_H
