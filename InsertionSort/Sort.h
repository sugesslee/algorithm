//
// Created by red on 2020/2/4.
//

#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

#include <algorithm>

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void insertionSort(T arr[], int N) {
    for (int i = 1; i < N; ++i) {
        T e = arr[i];
        int j;//保存j应该插入的位置
        for (j = i; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        swap(arr[j], e);
    }
}

#endif //ALGORITHM_SORT_H
