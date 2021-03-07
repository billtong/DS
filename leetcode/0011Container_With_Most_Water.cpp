#include "stdafx.h"

/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.
*/
class Solution11
{
public:
	/*
		Two Pointer Approach
		we take two pointers, one at start, and one at the end. becase the distance from middle are the same
		so we only need to compare there height and move the shorter one toward the middle.
		as moving the shorter one also has shorter distance, so it must be taller to beat the other half.
	*/
	int maxArea(vector<int>& height)
	{
		int i = 0, j = height.size() - 1;
		int max_area = 0;
		while (i < j)
		{
			int h = min(height[i], height[j]);
			max_area = max(max_area, h * (j - i));
			while (height[i] <= h && i < j)
				i++; // condition that there are constantly shorter ones
			while (height[j] <= h && i < j)
				j--;
		}
		return max_area;
	}

	/*
	a dynamic programming implementation
	O(n^2) too long  poor performance
	*/
	int maxArea_my_garbage_one(vector<int>& height)
	{
		int n = height.size();
		int* a = new int[n];
		memset(a, 0, n * sizeof(int));
		a[1] = area(height, 0, 1);
		for (int i = 2; i < n; i++)
		{
			int rslt = a[i - 1];
			for (int j = 1; j <= i; j++)
			{
				rslt = max(rslt, area(height, i - j, i));
			}
			a[i] = rslt;
		}
		return a[height.size() - 1];
	}

	inline int area(vector<int> height, int i, int j)
	{
		return min(height[i], height[j]) * (j - i);
	}
	inline int max(int a, int b)
	{
		return a > b ? a : b;
	}

	inline int min(int a, int b)
	{
		return a < b ? a : b;
	}
};

//void main()
//{
//	vector<int> h = { 1, 2, 1 };
//	Solution11 s;
//	cout << s.maxArea(h);
//}