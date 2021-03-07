#include "stdafx.h"

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution12
{
public:
	/*
	greedy strategy
	*/
	string intToRoman(int num)
	{
		int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		string rslt;
		for (int i = 0; num != 0; i++)
		{
			while (num >= value[i])
			{
				num -= value[i];
				rslt += symbol[i];
			}
		}
		return rslt;
	}
};
