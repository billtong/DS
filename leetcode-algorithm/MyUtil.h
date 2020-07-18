#pragma once

namespace my_util 
{

    inline int find_max(int num1, int num2)
    {
        return num1 > num2 ? num1 : num2;
    }


    inline int find_min(int num1, int num2)
    {
        return num1 < num2 ? num1 : num2;
    }

    void swap(int& a, int& b);

    void print_2d_array(char** ptr, int m, int n);
}
