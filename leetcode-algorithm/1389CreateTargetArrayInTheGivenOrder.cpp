#include "stdafx.h"

/*
Given two arrays of integers nums and index. Your task is to create target array under the following rules:
Initially target array is empty.
From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
Return the target array.
It is guaranteed that the insertion operations will be valid.

it would be too easy to implemented by vector::insert in cpp, so i use c
*/


int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
    *returnSize = numsSize; //place size value int the returnSize pointer
    int* target = (int*)malloc(sizeof(int) * numsSize);
    int i, j;
    for (i = 0; i < numsSize; i++) {
        for (j = i; j > index[i]; j--)
            target[j] = target[j - 1];
        target[index[i]] = nums[i];
    }
    return target;
}

// move memory
int* createTargetArray2(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
    int* target = (int *)malloc(sizeof(int) * numsSize);
    memset(target, -1, sizeof(int) * numsSize);
    for (int i = 0; i < indexSize; i++) {
        int j = index[i];
        if (target[j] != -1) memmove(&target[j + 1], &target[j], sizeof(int) * (indexSize - j - 1));
        target[j] = nums[i];
    }
    *returnSize = numsSize;
     return target;
}

