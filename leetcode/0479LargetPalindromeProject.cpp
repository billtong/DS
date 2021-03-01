#include "stdafx.h"

/**
 * Find the largest palindrome made from the product of two n-digit numbers.
 * Since the result could be very large, you should return the largest palindrome mod 1337.
 */
class Solution
{
private:
	// input 91 output 9119
	long genPalindrome(int n)
	{
		string s = to_string(n);
		reverse(s.begin(), s.end());
		return stol(to_string(n) + s);
	}

public:
	int largestPalindrome(int n)
	{
		if (n == 1)
			return 9;
		int u = pow(10, n) - 1;			 //the upper bound of each n-digit number 10^n - 1
		int l = pow(10, n - 1);			 //the lower bound of each n-digit number 10^(n-1)
		for (int i = u; i >= l; i--) //guess the palindrome product from the larget palindrome in the range
		{
			long pal = genPalindrome(i);
			for (long j = u; j * j >= pal; j--) // check if this palindrome satisfy
			{
				if (pal % j == 0 && pal / j <= u)
				{
					return pal % 1337;
				}
			}
		}
		return -1; //should not be reached
	}
};