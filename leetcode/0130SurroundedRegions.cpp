#include "stdafx.h"

/*
Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
其实就是翻转棋的规则
*/

class Solution
{
public:
	void solve(vector<vector<char>>& board)
	{
		int rowSize = board.size();
		if (rowSize == 0)
			return;
		int colSize = board[0].size();
		vector<vector<bool>> isOSurvive(rowSize, vector<bool>(colSize, false)); //whether O at position x,y on the board survived or not

		for (int first = 0, last = 0; first < colSize; first++, last++)
		{ //check the first and last row
			if (board[0][first] == 'O')
				dfs(board, 0, first, isOSurvive);
			if (board[rowSize - 1][last] == 'O')
				dfs(board, rowSize - 1, last, isOSurvive);
		}

		for (int first = 0, last = 0; first < rowSize; first++, last++)
		{ //check the first and last column
			if (board[first][0] == 'O')
				dfs(board, first, 0, isOSurvive);
			if (board[last][colSize - 1] == 'O')
				dfs(board, last, colSize - 1, isOSurvive);
		}

		for (int i = 0; i < rowSize; i++) // kill dead 'O's
			for (int j = 0; j < colSize; j++)
				if (board[i][j] == 'O' && !isOSurvive[i][j])
					board[i][j] = 'X';
	}

	// make depth first search from boundary.
	void dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& isOSurvive)
	{
		if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == 'X' || isOSurvive[x][y])
			return;								 // search out of border || not char 'o' || already survive
		isOSurvive[x][y] = true; //O at boundary or connect directly(move hebabour as below) with O survice
		dfs(board, x + 1, y, isOSurvive);
		dfs(board, x - 1, y, isOSurvive);
		dfs(board, x, y + 1, isOSurvive);
		dfs(board, x, y - 1, isOSurvive);
	}
};