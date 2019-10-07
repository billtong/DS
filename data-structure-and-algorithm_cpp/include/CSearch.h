#pragma once

#include<iostream>

class CSearch
{
public:
	static int binarySearch(int *a, int size, int x);
	static int trinarySearch(int* a, int size, int x);
	void execSearchFuncWithClock(int (*func)(int*, int, int), int* a, int size, int x);
};
