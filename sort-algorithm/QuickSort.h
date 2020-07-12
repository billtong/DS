#pragma once
#include "SortStrategy.h"

class QuickSort :
    public SortStrategy
{
public:
    void exec(int* arr, const int size);
private:
    void quick_sort_rec(int* arr, int left, int right);
    int find_pivot(int* arr, int left, int right);
};

class QuickSort2 :
    public SortStrategy
{
public:
    void exec(int* arr, const int size);
private:
    void quick_sort_rec(int* arr, int left, int right);
};

