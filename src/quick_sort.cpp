//
// Created by SENSETIME\yuxingyao on 18-5-6.
//
#include <iostream>
#include "quick_sort.h"
using namespace std;

int Partition(int *data, int start, int end, int length)
{
    if (data == NULL || start < 0 || length <= 0 || end >= length)
        throw "Error!\n";

    int index = rand() % (end - start + 1) + start;
    swap(data[index], data[end]);

    int small = start;
    for (int index = start; index < end; ++index) {
        if (data[index] <= data[end])
        {
            swap(data[index], data[small]);
            small ++ ;
        }
    }
    swap(data[small], data[end]);

    return small;
}

void QuickSort(int *data, int start, int end, int length)
{
    if(start == end)
        return;
    int index = Partition(data, start, end, length);
    if (index > start)
        QuickSort(data, start, index - 1, length);
    if (index < end)
        QuickSort(data, index + 1, end, length);
}

//int main(int argc, char **argv)
//{
//    int data[9] = {3,7,8,5,2,1,9,5,4};
//    int start = 0;
//    int end = 8;
//    int length = 9;
//
//    QuickSort(data, start, end, length);
//
//    for (int i = 0; i < length; ++i) {
//        cout << data[i] << '\t';
//    }
//    cout << endl;
//
//}