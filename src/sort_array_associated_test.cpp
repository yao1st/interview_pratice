//
// Created by senseadmin on 18-7-5.
//

#include "sort_array_associated.h"

int main()
{
    int arr[] = {1, 2, 4, 7, 11, 15};
    int length = sizeof(arr) / sizeof(arr[0]);
    int first = 0;
    int second = length - 1;
    int target_sum = 15;
    findTwoNumbersWithTargetSum(arr, &first, &second, target_sum);
    std::cout << arr[first] << " + " << arr[second] << " = " << target_sum << std::endl;
    findContinuousSequenceWithTargetSum(15);
}