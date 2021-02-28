#include "stdafx.h"

/**
 * Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. 
 * The same Fibonacci number can be used multiple times.
 */

// greedy algorithm
class Solution
{
private:
	vector<int> fi;
	void genFibonacci(int k)
	{
		int i = 1, j = 1;
		fi.push_back(1);
		fi.push_back(1);
		while (i <= k)
		{
			int temp = i + j;
			fi.push_back(i);
			i = j;
			j = temp;
		}
	}

public:
	int findMinFibonacciNumbers(int k)
	{
		genFibonacci(k);
		auto iter = fi.end() - 1;
		int res = 0;
		while (iter >= fi.begin() && k > 0)
		{
			if (k == *iter)
			{
				return res + 1;
			}
			else if (k > *iter)
			{
				k -= *iter;
				res++;
			}
			iter--;
		}
		return -1;
	}
};