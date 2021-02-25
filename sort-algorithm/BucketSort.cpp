#include "BucketSort.h"
#include <stdlib.h>
#include <math.h>

void BucketSort::exec(int *arr, const int size)
{
	this->bucket_sort(arr, size, _bucket_size);
}

/*
bucketSize needs to be the maximum value of the array
In order from small to large, count the number of each element,
Then take them all out and sort them
*/
void BucketSort::bucket_sort(int *a, int size, int bucket_size)
{
	int *buckets = (int *)malloc(sizeof(int) * bucket_size);
	for (int i = 0; i < bucket_size; i++)
		buckets[i] = 0;
	for (int i = 0; i < size; i++)
		buckets[a[i]]++;
	for (int i = 0, j = 0; j < bucket_size; j++)
	{
		int k = buckets[j];
		while (k > 0)
		{
			a[i++] = j;
			k--;
		}
	}
}

void RadixSort::exec(int *arr, const int size)
{
	this->radix_sort(arr, size, _p);
}

/*
Radix sorting is an improved version of bucketsort
bucketsize (0, 10^p)
sort Once place, then Tence place, and then Hundreds place...
In each cycle
1. After each number hashes (to get a quotient), use bucket sort; (count value assignment)
2. Calculate the sequence of each place value position according to the value of count of previous place (offset value assignment)
3. take out the value according to the situation of offset (temp value assignment)
4. arr=temp
*/
void RadixSort::radix_sort(int *a, int size, int p)
{
	for (int k = 0; k < p; k++) //base 10 is used
	{
		int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int *tmp = (int *)malloc(sizeof(int) * size);
		int *offset = (int *)malloc(sizeof(int) * 10);
		for (int i = 0; i < size; i++)
			count[(a[i] / (int)pow(10, k)) % 10]++;
		offset[0] = 0;
		for (int i = 1; i < 10; i++)
		{
			offset[i] = 0;
			for (int j = 0; j < i; j++)
				offset[i] += count[j];
		}
		for (int i = 0; i < size; i++)
			tmp[offset[(a[i] / (int)pow(10, k)) % 10]++] = a[i]; //look! here add one after place a value in the tmp array
		for (int i = 0; i < size; i++)
			a[i] = tmp[i];
	}
}
