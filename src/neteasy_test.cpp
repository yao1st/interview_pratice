//
// Created by senseadmin on 18-8-9.
//
#include <iostream>
#include <vector>
#define START_POINT 5000
int main(int argc, char **argv)
{
    int t;
    std::cin >> t;

    if (t < 0 || t > 100)
        return -1;

    std::vector<float> input_vec(t);

    for (int i = 0; i < t; ++i) {
        float data;
        std::cin >> data;
        if (data < 0 || data > 1000000)
            return -1;
        input_vec[i] = data - START_POINT;
    }

    std::vector<int> tax(t);
    float rate, tax_offset;
    for (int j = 0; j < input_vec.size(); ++j) {
        {
            float v = input_vec[j];
            if(v < 0.0)
                tax[j] = (int)0;
            else
            {
                if (v <= 3000);
                {
                    rate = 0.03;
                    tax_offset = 0.0;
                }
                else if (v <= 12000)
                {
                    rate = 0.1;
                    tax_offset = 3000 * (0.1 - 0.03);
                }
                else if (v <= 25000)
                {
                    rate = 0.2;
                    tax_offset = 12000 * (0.2 - 0.1) + 3000 * (0.1 - 0.03);
                }
                else if (v <= 35000)
                {
                    rate = 0.25;
                    tax_offset = 25000 * (0.25 - 0.2) + 12000 * (0.2 - 0.1) + 3000 * (0.1 - 0.03);
                }
                else if (v <= 55000)
                {
                    rate = 0.3;
                    tax_offset = 35000 * (0.3 - 0.25) + 25000 * (0.25 - 0.2) + 12000 * (0.2 - 0.1) + 3000 * (0.1 - 0.03);
                }
                else if (v <= 80000)
                {
                    rate = 0.35;
                    tax_offset = 55000 * (0.35 - 0.3) + 35000 * (0.3 - 0.25) + 25000 * (0.25 - 0.2) + 12000 * (0.2 - 0.1) + 3000 * (0.1 - 0.03);
                }
                else
                {
                    rate = 0.45;
                    tax_offset = 80000 * (0.45 - 0.35) 55000 * (0.35 - 0.3) + 35000 * (0.3 - 0.25) + 25000 * (0.25 - 0.2) + 12000 * (0.2 - 0.1) + 3000 * (0.1 - 0.03);
                }
                tax[j] = (int) (v * rate + tax_offset);
            }
        }

    }

    for (int k = 0; k < t; ++k) {
        std::cout << tax[k] << std::endl;
    }
}
