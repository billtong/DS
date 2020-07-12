#include "SortContext.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "BucketSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Tools.h"

#include <stdio.h>
#include <stdlib.h>

void initArray(int* a)
{
	a[0] = 10;
	a[1] = 24;
	a[2] = 5;
	a[3] = 32;
	a[4] = 1;
	a[5] = 84;
	a[6] = 19;
}

int main()
{
	int a[] = { 10, 24, 5, 32, 1, 84, 19 };
	int n = 7;
	printf("Before   Sorting:\t");
	Tools::print_array(a, n);
	printf("*****\n");

	initArray(a);
	SelectionSort ss;
	SortContext c(&ss);
	c.exec(a, 7);
	printf("selection sort result:\n");
	Tools::print_array(a, n);

	initArray(a);
	LinearInsertionSort lis;
	c.set_sort_stragetegy(&lis);
	c.exec(a, 7);
	printf("linear insertion1 sort result:\n");
	Tools::print_array(a, n);

	initArray(a);
	LinearInsertionSort2 lis2;
	c.set_sort_stragetegy(&lis2);
	c.exec(a, 7);
	printf("linear insertion2 sort result:\n");
	Tools::print_array(a, n);
	
	initArray(a);
	BinaryInsertionSort bis;
	c.set_sort_stragetegy(&bis);
	c.exec(a, 7);
	printf("binary insertion sort result:\n");
	Tools::print_array(a, n);

	initArray(a);
	BubbleSort bs;
	c.set_sort_stragetegy(&bs);
	c.exec(a, 7);
	printf("bubble sort result:\n");
	Tools::print_array(a, n);

	int test[] = { 200, 50, 212, 23, 43, 7, 1200, 50, 60, 2, 5, 3, 1 };//s13
	QuickSort qs;
	c.set_sort_stragetegy(&qs);
	c.exec(test, 13);
	printf("quick sort result:\n");
	Tools::print_array(test, 13);
	
	int test1[] = { 200, 50, 212, 23, 43, 7, 1200, 50, 60, 2, 5, 3, 1 };//s13
	QuickSort2 qs2;
	c.set_sort_stragetegy(&qs2);
	c.exec(test1, 13);
	printf("quick sort2 result:\n");
	Tools::print_array(test1, 13);
	
	int test2[] = { 200, 50, 212, 23, 43, 7, 1200, 50, 60, 2, 5, 3, 1 };//s13
	MergeSort ms;
	c.set_sort_stragetegy(&ms);
	c.exec(test2, 13);
	printf("merge sort result:\n");
	Tools::print_array(test2, 13);
	
	int test3[] = { 3, 1, 2, 2, 5, 9, 2, 4, 4, 1, 6, 9, 0, 1, 2 };
	BucketSort bks;
	c.set_sort_stragetegy(&bks);
	c.exec(test3, 15);
	printf("bucket sort result:\n");
	Tools::print_array(test3, 15);
	
	int test4[] = { 629, 202, 40, 593, 2, 131, 34, 23,13, 1, 12, 23, 43, 53, 90 };
	RadixSort rs;
	c.set_sort_stragetegy(&rs);
	c.exec(test4, 15);
	printf("radix sort result:\n");
	Tools::print_array(test4, 15);

	system("pause");
	return 0;
}

