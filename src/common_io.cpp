//
// Created by senseadmin on 18-7-9.
//

#include "common_io.h"

void getArrayDividedBySpace(int *arr, int *length)
{
    std::string input_string;
    std::cout << "input integer array divided by space" << std::endl;
    std::getline(std::cin, input_string);
    std::istringstream iss(input_string);
    *length = 0;

    while (iss >> arr[*length])
    {
        (*length) ++;
    }
}

void printArray(int *arr, int length)
{
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
}


int main()
{
    int *arr_buffer = new int[1024];
    int length = 0;
    getArrayDividedBySpace(arr_buffer, &length);
    printArray(arr_buffer, length);
}
