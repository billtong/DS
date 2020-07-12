#pragma once
#include "SortStrategy.h"
class MergeSort :
    public SortStrategy
{
public:
    void exec(int* arr, const int size);
private:
    void merge_sort_rec(int* a, int start, int end, int* b);
    void merge(int* a, int start, int middle, int end, int* b);
};

