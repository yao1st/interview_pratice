//
// Created by senseadmin on 18-7-5.
//

#include "bit_operation_associated.h"

int main()
{
    int arr[] = {2, 4, 3, 6, 3, 2, 5, 5};
    int num1, num2;
    findTwoNumberOnlyAppearedTwice(arr, sizeof(arr) / sizeof(arr[0]), &num1, &num2);
    std::cout << "result is : " << num1 << '\t' << num2 << std::endl;
    return 0;
}