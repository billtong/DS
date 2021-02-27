#include "stdafx.h"

//Given an integer, return its base 7 string representation.

class Solution
{
public:
	string convertToBase7(int num)
	{
		string res = "";
		bool isNeg = false;
		if (num == 0)
			return "0";
		if (num < 0)
		{
			isNeg = true;
			num = -num;
		}
		while (num > 0)
		{
			int x = num % y;
			num /= 7;
			res = to_string(x) + res;
		}
		return isNeg ? "-" + res : res;
	}
};