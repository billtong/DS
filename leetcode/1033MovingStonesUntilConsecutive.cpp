#include "stdafx.h"

/**
 * Three stones are on a number line at positions a, b, and c.
 * Each turn, you pick up a stone at an endpoint (ie., either the lowest or highest position stone), 
 * and move it to an unoccupied position between those endpoints.  
 * Formally, let's say the stones are currently at positions x, y, z with x < y < z.  
 * You pick up the stone at either position x or position z, and move that stone to an integer position k, with x < k < z and k != y.
 * The game ends when you cannot make any more moves, ie. the stones are in consecutive positions.
 * When the game ends, what is the minimum and maximum number of moves that you could have made?  
 * Return the answer as an length 2 array: answer = [minimum_moves, maximum_moves]
 */

class Solution
{
public:
	vector<int> numMovesStones(int a, int b, int c)
	{
		if (a > b)
			return numMovesStones(b, a, c);
		if (b > c)
			return numMovesStones(a, c, b);
		int d1 = b - a - 1, d2 = c - b - 1;
		return vector<int>{d1 == 0 && d2 == 0 ? 0 : d1 <= 1 || d2 <= 1 ? 1
																																	 : 2,
											 d1 + d2};
	}
};