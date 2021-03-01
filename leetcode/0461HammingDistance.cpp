/**
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * Given two integers x and y, calculate the Hamming distance.
 */

class Solution
{
public:
	int hammingDistance(int x, int y)
	{
		int diff = 0;
		while (x || y)
		{
			if (x % 2 != y % 2)
				diff++;
			x /= 2;
			y /= 2;
		}
		return diff;
	}
};
