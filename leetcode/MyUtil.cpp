#include "MyUtil.h"
#include <iostream>

void my_util::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//void main()
//{
//    int** a = new int*[10];
//    for (int i = 0; i < 10; i++)
//    {
//        a[i] = new int[10];
//        memset(a[i], 0, 10);
//    }
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//            a[i][j] = i * j;
//    }
//    PRINT_2D_ARRAY(a, 10, 10);
//}