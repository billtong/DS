#pragma once
#include "SortStrategy.h"

class LinearInsertionSort :
    public SortStrategy
{
public:
    void exec(int* arr, const int size);
};

class LinearInsertionSort2 :
    public SortStrategy
{
public:
    void exec(int* arr, const int size);
};

class BinaryInsertionSort :
    public SortStrategy
{
public:
    void exec(int* arr, const int size);
};