//
// Created by red on 2020/2/3.
//
#include <algorithm>
#include <iostream>
#include "Student.h"
#include "../Sort/SortTestHelper.h"

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

int main() {
    int N = 20000;
    int *arr = SortTestHelper::generatorRandomArray(N, 0, N);
    SortTestHelper::testSort("selection sort", selectionSort, arr, N);
    SortTestHelper::printArray(arr, N);
    delete[] arr;

    // 测试模板函数，传入自定义结构体Student数组
    Student d[4] = {{"D", 90},
                    {"C", 100},
                    {"B", 95},
                    {"A", 95}};
    selectionSort(d, 4);
    for (const auto &i : d)
        cout << i;
    cout << endl;

    return 0;
}