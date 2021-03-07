#include "stdafx.h"

/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible,
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number,
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number,
or if no such sequence exists because either str is empty or it contains only whitespace characters,
no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
*/

class Solution8
{
public:
	/*
	almost copy from question 7 reverse integer
	add some if judgement
	*/
	int myAtoi(string str)
	{
		int n = str.length();
		int res = 0;
		int iter = 0;
		bool is_positive = true;
		while (str[iter] < '0' || str[iter] > '9')
		{
			if (str[iter] == '-')
			{
				is_positive = false;
				iter++;
				break;
			}
			else if (str[iter] == '+')
			{
				iter++;
				break;
			}
			else if (str[iter] == ' ')
				iter++;
			else
				return 0;
		}

		for (int i = iter; i < n; i++)
		{
			if (str[i] < '0' || str[i] > '9')
				return res;
			int pop = is_positive ? str[i] - '0' : '0' - str[i];
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7))
				return INT_MAX;
			if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8))
				return INT_MIN;
			res = res * 10 + pop;
		}
		return res;
	}
};

//void main()
//{
//    Solution8 s;
//    cout << s.myAtoi("4193 with words");
//}
