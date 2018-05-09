//
// Created by SENSETIME\yuxingyao on 18-5-6.
//

#include <iostream>
#include "quick_sort.h"
using namespace std;

bool IsValidResult(int *data, int length, int result)
{
    int num = 0;
    for (int i = 0; i < length; ++i) {
        if (data[i] == result)
            num++;
    }
    if (num * 2 <= length)
        return false;
    return true;
}

int MoreThanHalfNum(int *data, int length)
{
    if (data == NULL || length <= 0)
        throw "Error!\n";

    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(data, start, end, length);
    while (index != middle)
    {
        if (index > middle)
        {
            end = index - 1;
            index = Partition(data, start, end, length);
        }
        else
        {
            start = index + 1;
            index = Partition(data, start, end, length);
        }

    }
    
    int result = data[middle];
    if(IsValidResult(data, length, result))
        return result;
    else
    {
        cout << " None exits.\n" << endl;
        return -1;
    }
}

int main(int argc, char **argv)
{
    int data[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int length = 9;
    
    int result = MoreThanHalfNum(data, length);
    cout << result <<endl;
}