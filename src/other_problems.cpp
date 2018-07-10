//
// Created by senseadmin on 18-7-9.
//
#include <math.h>
#include <iostream>

int max_dice_point = 6;

int sumOfArraySlice(int *arr, int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += arr[i];
    }
    return sum;
}

void printDiceSumProbability(int dice_number)
{
    int *sum_appeared_time[2];
    int sum_arr_length = max_dice_point * dice_number;
    sum_appeared_time[0] = new int [sum_arr_length];
    sum_appeared_time[1] = new int [sum_arr_length];

    for (int i = 0; i < max_dice_point; ++i) {
        sum_appeared_time[0][i] = 1;
        sum_appeared_time[1][i] = 0;
    }

    int flag = 0;
    for (int j = 1; j < dice_number; ++j) {
        for (int i = 0; i < j; ++i) {
            sum_appeared_time[flag][i] = 0;
        }
        for (int k = j; k < (j+1)*max_dice_point; ++k) {
            sum_appeared_time[1 - flag][k] = sumOfArraySlice(sum_appeared_time[flag], (k-max_dice_point>0)?k-max_dice_point:0, k-1);
        }
        flag = 1 - flag;
    }

    double total_times = pow(max_dice_point, dice_number);
    for (int l = 0; l < sum_arr_length; ++l) {
        std::cout << "P(sum=" << l+1 << ")=" << sum_appeared_time[flag][l] / total_times << std::endl;
    }
}



int main()
{
    int dice_number = 2;
    printDiceSumProbability(dice_number);
}
