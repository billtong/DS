#include "stdafx.h"

/**
 * Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
 * 	1 which means a street connecting the left cell and the right cell.
 * 	2 which means a street connecting the upper cell and the lower cell.
 * 	3 which means a street connecting the left cell and the lower cell.
 * 	4 which means a street connecting the right cell and the lower cell.
 * 	5 which means a street connecting the left cell and the upper cell.
 * 	6 which means a street connecting the right cell and the upper cell.
 * You will initially start at the street of the upper-left cell (0,0). 
 * A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). 
 * The path should only follow the streets.
 * Notice that you are not allowed to change any street.
 * Return true if there is a valid path in the grid or false otherwise.
 */

//dfs search tree
class Solution
{
private:
	// row is direction; col is street type
	const vector<vector<bool>> rule = {{1, 0, 1, 0, 1, 0},	//left
																		 {0, 1, 0, 0, 1, 1},	//up
																		 {1, 0, 0, 1, 0, 1},	//right
																		 {0, 1, 1, 1, 0, 0}}; //down
	vector<vector<int>> grid;
	vector<vector<bool>> visited;
	bool ans = false;

public:
	bool hasValidPath(vector<vector<int>> &grid)
	{
		this->grid = grid;
		visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
		return dfs(0, 0);
	}

	bool dfs(int row, int col)
	{
		int s = grid[row][col], m = grid.size(), n = grid[0].size();
		if (ans || (row == m - 1 && col == n - 1)) //returns if ans is true already
		{
			return true;
		}
		visited[row][col] = true;
		if (rule[0][s - 1])
		{ //left col - 1
			if (col - 1 >= 0 && col - 1 < n && rule[2][grid[row][col - 1] - 1] && visited[row][col - 1] == false)
				ans = dfs(row, col - 1);
		}

		if (rule[1][s - 1])
		{ //up row - 1
			if (row - 1 >= 0 && row - 1 < m && rule[3][grid[row - 1][col] - 1] && visited[row - 1][col] == false)
				ans = dfs(row - 1, col);
		}

		if (rule[2][s - 1])
		{ //right col + 1
			if (col + 1 >= 0 && col + 1 < n && rule[0][grid[row][col + 1] - 1] && visited[row][col + 1] == false)
				ans = dfs(row, col + 1);
		}

		if (rule[3][s - 1])
		{ //down row + 1
			if (row + 1 >= 0 && row + 1 < m && rule[1][grid[row + 1][col] - 1] && visited[row + 1][col] == false)
				ans = dfs(row + 1, col);
		}
		return ans;
	}
};