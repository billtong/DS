#include "stdafx.h"
#include "MyUtil.h"

using namespace my_util;

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
"string convert(string s, int numRows); "
Example 1:
	Input: s = "PAYPALISHIRING", numRows = 3
	Output: "PAHNAPLSIIGYIR"
Example 2:
	Input: s = "PAYPALISHIRING", numRows = 4
	Output: "PINALSIGYAHRPI"
	Explanation:
	P     I    N
	A   L S  I G
	Y A   H R
	P     I
*/
class Solution6
{
public:
	/*
	match solution

	0*cyc+0					1*cyc+0					...
	0*cyc+1	0*cyc+(cyc-1)	1*cyc+1 1*cyc+(cyc-1)	...
	0*cyc+2	0*cyc+(cyc-2)	1*cyc+2 1*cyc+(cyc-2)	...
	...		...				...	
	0*cyc+(num_rows-1)		1*cyc+(num_rows-1) ...

	j is col * cycle_len
	i is row

	outer loop through the remains i ~ [0, num_rows)
	inner loop through the values j ~ 0*cyc to j + i < string size
	
	in the inner loop there are two cases
		1. i == 0 or i == num_rows-1 or the others but out of the bounds
			there is only one element needs to be taken
		2. others
			there are two elements needs to be taken.
	*/
	string convert1(string s, int numRows)
	{
		if (s.empty() || numRows == 1)
			return s;
		int n = s.size();
		int cyc_len = numRows * 2 - 2;
		string ns;
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j + i < n; j += cyc_len)
			{
				ns += s.at(j + i);
				if (i != 0 && i != numRows - 1 && j + cyc_len - i < n)
					ns += s.at(j + cyc_len - i);
			}
		}
		return ns;
	}

	/*
	 to record my stupidness by keep this stupid solution
	string s => table[remainer][devide value] => table[column][sequence in the column] => get the converted string ns
	*/
	string convert_my(string s, int numRows)
	{
		if (s.empty() || numRows == 1)
			return s;
		int str_len = s.length();
		int cycle_len = numRows * 2 - 2;
		int b = (str_len - 1) / cycle_len + 1;
		char wildcard = '*';
		char **t1 = this->init_table(cycle_len, b, wildcard);
		for (int i = 0; i < str_len; i++)
			t1[i % cycle_len][i / cycle_len] = s.at(i);
		char **t2 = this->init_table(numRows - 2, 2 * b, wildcard);
		for (int i = 1; i < cycle_len / 2; i++)
		{
			for (int j = 0; j < b; j++)
			{

				t2[i - 1][2 * j] = t1[i][j];
				t2[i - 1][2 * j + 1] = t1[cycle_len - i][j];
			}
		}
		string ns;
		for (int i = 0; i < b; i++)
			ns += t1[0][i];
		for (int i = 0; i < numRows - 2; i++)
		{
			for (int j = 0; j < 2 * b; j++)
			{
				if (t2[i][j] == wildcard)
					continue;
				else
					ns += t2[i][j];
			}
		}
		for (int i = 0; i < b; i++)
		{
			if (t1[cycle_len / 2][i] == wildcard)
				continue;
			else
				ns += t1[cycle_len / 2][i];
		}
		return ns;
	}

	// initialize a 2d character array
	char **init_table(int m, int n, char default_char)
	{
		char **t = new char *[m];
		for (int i = 0; i < m; i++)
		{
			t[i] = new char[n];
			memset(t[i], default_char, n);
		}
		return t;
	}
};

//void main()
//{
//	Solution6 s;
//	cout << s.convert("PAYPALISHIRING", 3);
//}