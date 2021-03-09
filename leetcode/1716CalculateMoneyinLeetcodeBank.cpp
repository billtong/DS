#include "stdafx.h"

/**
 * Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
 * He starts by putting in $1 on Monday, the first day. 
 * Every day from Tuesday to Sunday, he will put in $1 more than the day before. 
 * On every subsequent Monday, he will put in $1 more than the previous Monday.
 * Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.
 */

class Solution
{
public:
	
	// S = (2 * a1 + d * (n - 1)) * n / 2
	int totalMoney(int n)
	{
		int div = n / 7, rem = n % 7;
		return (2 * 28 + 7 * (div - 1)) * div / 2 + (2 * (div + 1) + rem - 1) * rem / 2;
	}
};