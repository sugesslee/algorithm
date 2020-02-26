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

// 对arr[l...r]范围的数组进行插入排序
template<typename T>
void insertionSort(T arr[], int l, int r) {

    for (int i = l + 1; i <= r; i++) {

        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j - 1] > e; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }

    return;
}

template<typename T>
void bubbleSort(T arr[], int N) {
    //pos变量用来标记循环里最后一次交换的位置
    int k = N - 1, pos = 0;
    for (int j = k; j >= 0; --j) {
        //每次遍历标志位都要先置为0，才能判断后面的元素是否发生了交换
        int flag = 0;
        for (int i = 0; i < k; ++i) {
            if (arr[i] > arr[i + 1]) {
//                swap(arr[i], arr[i + 1]);
//                //只要有发生了交换，flag就置为1
//                flag = 1;
                swap(arr[i], arr[i + 1]);
                flag = 1;   //只要有发生了交换，flag就置为1
                pos = i;    //循环里最后一次交换的位置 i 赋给pos
            }
        }
        k = pos;
        //判断标志位是否为0，如果为0，说明后面的元素已经有序，就直接return
        if (flag == 0) {
            return;
        }
    }
}


#endif //ALGORITHM_SORT_H
