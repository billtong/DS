#include "MyUtil.h"
#include <iostream>

void my_util::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void my_util::print_2d_array(char** ptr, int m, int n)
{
    std::cout << "2d array:" << std::endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << ptr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "2d array ends" << std::endl;
}
