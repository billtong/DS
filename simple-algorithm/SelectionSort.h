#pragma once
#include "SortStrategy.h"

class SelectionSort :
    public SortStrategy
{
public:
    void exec(int *arr, const int size);
};
