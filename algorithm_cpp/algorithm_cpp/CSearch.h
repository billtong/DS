#pragma once

#include<iostream>
using std::cout;

class CSearch
{
public:
	static int binarySearch(int *a, int size, int x);
	static int trinarySearch(int* a, int size, int x);
};

//	int a[10] = { 1, 3, 6, 8, 10, 12, 32, 33, 34, 40 };