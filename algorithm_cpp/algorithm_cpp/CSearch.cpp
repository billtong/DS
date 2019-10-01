#include "CSearch.h"

int CSearch::binarySearch(int* a, int size, int x)
{
	int first = 0;
	int last = size - 1;
	while (first <= last) 
	{
		int mid = (first + last) / 2;
		if (a[mid] == x)
		{
			return mid;
		}
		else if (a[mid] > x) 
		{
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	return -1;
}

int CSearch::trinarySearch(int* a, int size, int x)
{
	int first = 0;
	int last = size - 1;
	while (first <= last) 
	{
		int t = first + (last - first) / 3;
		if (a[t] == x)
		{
			return t;
		}
		else if (a[t] > x)
		{
			last = t - 1;
		}
		else
		{
			first = t + 1;
			if (first > last)
			{
				return -1;
			}
			int mid = (first + last) / 2;
			if (a[mid] == x)
			{
				return mid;
			}
			else if (a[mid] > x)
			{
				last = mid - 1;
			}
			else 
			{
				first = mid + 1;
			}
		}
	}
	return -1;
}
