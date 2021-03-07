#include "stdafx.h"

/*
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
*/

class Solution7
{
public:
	/*
	loop util x=0
		pop = x%10
		check rev*10 and rev*10

		rev = rev*10 +pop
	 */
	int reverse1(int x)
	{
		int res = 0;
		while (x)
		{
			int pop = x % 10;
			x /= 10;
			// this can avoid generating any overflow value
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7))
				return 0; //INT_MAX: 2147483647
			if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8))
				return 0; //INT_MIN: -2147483648
			res = res * 10 + pop;
		}
		return res;
	}

	/*
	 my dump solution
	*/
	int reverse(int x)
	{
		int temp = x;
		vector<int> v;
		bool is_tail = true;
		while (x)
		{
			if (is_tail)
			{
				if (x % 10)
				{
					is_tail = false;
					v.push_back(x % 10);
				}
			}
			else
			{
				v.push_back(x % 10);
			}

			x /= 10;
		}
		long res = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (res + v[i] * pow(10, v.size() - i - 1) > INT_MAX || res + v[i] * pow(10, v.size() - i - 1) < INT_MIN)
				return 0;
			res = res + v[i] * pow(10, v.size() - i - 1);
		}
		return res;
	}
};

//void main()
//{
//    Solution7 s;
//    cout << s.reverse(-1534);
//
//}