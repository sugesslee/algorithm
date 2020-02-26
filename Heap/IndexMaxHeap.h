//
// Created by red on 2020/2/26.
//

#ifndef ALGORITHM_INDEXMAXHEAP_H
#define ALGORITHM_INDEXMAXHEAP_H

#include <cassert>
#include <algorithm>
#include <iostream>

using namespace std;

// 最大索引堆
template<typename Item>
class IndexMaxHeap {
private:
    Item *data; // 最大索引堆中的数据
    int *indexes;  // 最大索引堆中的索引
    int *reverse;  // 最大索引堆中的反向索引，reverse[i] = x表示索引i在x的位置

    int count;
    int capacity;

    // 索引堆中，数据之间的比较根据data数值比较，但是操作的是data的索引
    void shiftUp(int k) {
        while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
            swap(indexes[k / 2], indexes[k]);
            reverse[indexes[k / 2]] = k / 2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {
            int j = 2 * k;
            if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
                j++;
            if (data[indexes[k]] >= data[indexes[j]])
                break;
            swap(indexes[j], indexes[k]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:

// 构造函数，构造一个空的索引堆，可容纳capacity个元素
    IndexMaxHeap(int capacity) {
        data = new Item[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity+1];
        for( int i = 0 ; i <= capacity ; i ++ )
            reverse[i] = 0;
        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    // 返回索引堆中元素个数
    int size() {
        return count;
    }

    // 判断堆是否为空
    bool isEmpty() {
        return count == 0;
    }

    // 向最大堆中插入一个元素，元素索引为i，元素为item
    // 传入的i，对用户来说是从0开始
    void insert(int i, Item item) {
        assert(count + 1 <= capacity);
        assert(i + 1 >= 1 && i + 1 <= capacity);

        i += 1;
        data[i] = item;
        indexes[count + 1] = i;
        reverse[i] = count + 1;
        count++;

        shiftUp(count);
    }

    // 从堆中取出最大元素即堆顶元素
    Item extractMax() {
        assert(count > 0);

        Item result = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        reverse[indexes[count]] = 0;
        count--;

        if (count) {
            reverse[indexes[1]] = 1;
            shiftDown(1);
        }

        return result;
    }

    // 从堆中取出最大元素的索引值
    int extractMaxIndex() {
        assert(count > 0);

        int result = indexes[1] - 1;
        swap(indexes[1], indexes[count]);
        reverse[indexes[count]] = 0;
        count--;
        if (count) {
            reverse[indexes[1]] = 1;
            shiftDown(1);
        }

        return result;
    }

    // 取最大索引堆中的堆顶元素
    Item getMax() {
        assert(count > 0);
        return data[indexes[1]];
    }

    // 取最大索引堆中的堆顶元素索引
    int getMaxIndex() {
        assert(count > 0);
        return indexes[1] - 1;
    }

    // 获取最大索引堆中index为i的元素
    Item getItem(int i) {
        assert(i + 1 > 1 && i + 1 <= capacity);

        return data[i + 1];
    }

    // 将最大索引堆中的索引为i的元素修改值
    void change(int i, Item newItem) {
        i += 1;
        data[i] = newItem;
        // 找到index[j] = i，j表示data[i]在堆中的位置
        // 之后shiftUp，再shiftDown
//        for (int j = 1; j <= count; ++j) {
//            if (indexes[j] == i) {
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }
//        }
        shiftUp(reverse[i]);
        shiftDown(reverse[i]);
    }

// 测试索引堆中的索引数组index
    // 注意:这个测试在向堆中插入元素以后, 不进行extract操作有效
    bool testIndexes() {

        int *copyIndexes = new int[count + 1];

        for (int i = 0; i <= count; i++)
            copyIndexes[i] = indexes[i];

        copyIndexes[0] = 0;
        std::sort(copyIndexes, copyIndexes + count + 1);

        // 在对索引堆中的索引进行排序后, 应该正好是1...count这count个索引
        bool res = true;
        for (int i = 1; i <= count; i++)
            if (copyIndexes[i - 1] + 1 != copyIndexes[i]) {
                res = false;
                break;
            }

        delete[] copyIndexes;

        if (!res) {
            cout << "Error!" << endl;
            return false;
        }

        return true;
    }


    // 测试索引堆中的索引数组index和反向数组reverse
    // 注意:这个测试在向堆中插入元素以后, 不进行extract操作有效
    bool testIndexesAndReverseIndexes(){

        int *copyIndexes = new int[count+1];
        int *copyReverseIndexes = new int[count+1];

        for( int i = 0 ; i <= count ; i ++ ){
            copyIndexes[i] = indexes[i];
            copyReverseIndexes[i] = reverse[i];
        }

        copyIndexes[0] = copyReverseIndexes[0] = 0;
        std::sort(copyIndexes, copyIndexes + count + 1);
        std::sort(copyReverseIndexes, copyReverseIndexes + count + 1);

        // 在对索引堆中的索引和反向索引进行排序后,
        // 两个数组都应该正好是1...count这count个索引
        bool res = true;
        for( int i = 1 ; i <= count ; i ++ )
            if( copyIndexes[i-1] + 1 != copyIndexes[i] ||
                copyReverseIndexes[i-1] + 1 != copyReverseIndexes[i] ){
                res = false;
                break;
            }

        delete[] copyIndexes;
        delete[] copyReverseIndexes;

        if( !res ){
            cout<<"Error!"<<endl;
            return false;
        }

        for( int i = 1 ; i <= count ; i ++ )
            if( reverse[ indexes[i] ] != i ){
                cout<<"Error 2"<<endl;
                return false;
            }

        return true;
    }
};


#endif //ALGORITHM_INDEXMAXHEAP_H
