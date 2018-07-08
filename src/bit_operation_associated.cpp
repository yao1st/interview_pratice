//
// Created by senseadmin on 18-7-5.
//

#include "bit_operation_associated.h"

bool isXthBit1(int num, int bit_loc)
{
    num = num >> bit_loc;
    return (num & 1);
}

void findTwoNumberOnlyAppearedTwice(int *arr, int length, int *num1, int *num2)
{
    if (arr == NULL || length < 2)
        return;
    int result_xor = arr[0];
    for (int i = 1; i < length; ++i) {
        result_xor ^= arr[i];
    }

    int bits = 0;
    while (!(result_xor & 1) && bits < 8 * sizeof(int))
    {
        result_xor = result_xor >> 1;
        bits++;
    }

    *num1 = 0; *num2 = 0;

    for (int j = 0; j < length; ++j) {
        if (isXthBit1(arr[j], bits))
        {
            (*num1) ^= arr[j];
        }
        else
        {
            (*num2) ^= arr[j];
        }
    }
}

