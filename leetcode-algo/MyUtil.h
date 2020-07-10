#pragma once

namespace my_util 
{
    inline void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    inline int find_max(int num1, int num2)
    {
        return num1 > num2 ? num1 : num2;
    }


    inline int find_min(int num1, int num2)
    {
        return num1 < num2 ? num1 : num2;
    }
}