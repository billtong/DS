#include "stdafx.h"

/**
 * There is an m by n grid with ball.
 * Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four direcctions
 * However you can at most move N times.
 * Find out the number of paths to move the ball out of grid boundary.
 * The answer may be very large, return it after mod 10^9 + 7.
 */
class Solution
{
private:
	const int MOD = pow(10, 9) + 7;
	int count = 0;

public:
	int findPaths(int m, int n, int N, int i, int j)
	{
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[i][j] = 1; //set inistal entry
		for (int moves = 1; moves <= N; moves++)
		{
			vector<vector<int>> temp(m, vector<int>(n, 0)); //use temp to update moves at grids
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					// update count if (i,j) is at boudnary
					// update two times at corners
					if (i == 0)
						count = (count + dp[i][j]) % MOD;
					if (j == 0)
						count = (count + dp[i][j]) % MOD;
					if (i == m - 1)
						count = (count + dp[i][j]) % MOD;
					if (j == n - 1)
						count = (count + dp[i][j]) % MOD;
					//add solutions from all four directions, the core dp function
					temp[i][j] = (((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % MOD + ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % MOD) % MOD;
				}
			}
			dp = temp; //update dp grid
		}
		return count;
	}
};