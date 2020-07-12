#pragma once
#include "SortStrategy.h"

class BucketSort :
    public SortStrategy
{
public:
    void exec(int* arr, const int size);
private:
    const int _bucket_size = 10;
    void bucket_sort(int* a, int size, int bucket_size);
private:

};

class RadixSort :
    public SortStrategy
{
public:
    void exec(int* arr, const int size);
private:
    const int _p = 3;
    void radix_sort(int* a, int size, int p);
};
