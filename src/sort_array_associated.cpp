//
// Created by senseadmin on 18-7-5.
//

#include <vector>
#include "sort_array_associated.h"

void findTwoNumbersWithTargetSum(int *arr, int *first, int *second, int target_sum)
{
    if (arr == NULL)
        return;
    while(first < second)
    {
        if (arr[*first] + arr[*second] == target_sum)
            return;
        else
        {
            if (arr[*first] + arr[*second] < target_sum)
                (*first)++;
            else
                (*second)--;
        }
    }
}

void printSequence(int start, int end)
{
    for (int i = start; i <= end; ++i) {
        std::cout << i << '\t';
    }
    std::cout << std::endl;
}

int sumOfSequence(int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += i;
    }
    return sum;
}

void findContinuousSequenceWithTargetSum(int target_sum)
{
    int small = 1;
    int big = 2;
    while (small < big && big <= target_sum / 2 + 1)
    {
        int sum = sumOfSequence(small, big);
        if (sum == target_sum)
        {
            printSequence(small, big);
            small ++;
        }
        else
        {
            if (sum < target_sum)
            {
                big ++;
            }
            else
            {
                small ++;
            }
        }
    }
}