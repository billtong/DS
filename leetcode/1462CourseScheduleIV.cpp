#include "stdafx.h"

/**
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * Some courses may have direct prerequisites, for example, to take course 0 you have first to take course 1, which is expressed as a pair: [1,0]
 * Given the total number of courses n, a list of direct prerequisite pairs and a list of queries pairs.
 * You should answer for each queries[i] whether the course queries[i][0] is a prerequisite of the course queries[i][1] or not.
 * Return a list of boolean, the answers to the given queries.
 * Please note that if course a is a prerequisite of course b and course b is a prerequisite of course c, then, course a is a prerequisite of course c.
 */

//graph bfs
class Solution
{
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
	{
		vector<vector<bool>> graph(n, vector<bool>(n, false));
		vector<bool> ans;
		queue<int> q;

		for (auto pair : prerequisites)	//read all the prerequisites informations
			graph[pair[0]][pair[1]] = true;

		for (int i = 0; i < n; i++)	//perfor bfs on every course
		{
			for (int j = 0; j < n; j++)	//push child nodes of course i into queue
				if (graph[i][j])
					q.push(j);
			while (!q.empty())
			{
				for (int j = 0; j < n; j++)
				{
					if (graph[q.front()][j] && !graph[i][j])	//prevent search unecessary nodes
					{
						graph[i][j] = true;
						q.push(j);
					}
				}
				q.pop();
			}
		}

		for (auto pair : queries)	//iterate queries and get answers
			ans.push_back(graph[pair[0]][pair[1]]);
		return ans;
	}
};
