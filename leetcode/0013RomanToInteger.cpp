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

class Solution13
{
public:
	int romanToInt(string s)
	{
		int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int rslt = 0;
		for (int i = 0, j = 0; j < s.length(); i++)
		{
			int len = symbol[i].length();
			while (s.substr(j, len) == symbol[i])
			{
				j += len;
				rslt += value[i];
			}
		}
		return rslt;
	}
};

//void main()
//{
//    Solution13 s;
//    cout << s.romanToInt("III");
//}