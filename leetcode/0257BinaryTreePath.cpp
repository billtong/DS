#include "stdafx.h"

/**
* Given a binary tree, return all root-to-leaf paths
*/

class Solution 
{
private:
	vector<string> paths;
public:
    vector<string> binaryTreePaths(TreeNode* root) 
	{
		if (!root) return vector<string>{};
		dfs(root, "");
		return paths;
	}

	void dfs(TreeNode* node, string path)
	{
		string newPath = path + to_string(node->val) + "->";
		if (node->left) dfs(node->left, newPath);
		if (node->right) dfs(node->right, newPath);
		if (!node->left && !node->right) paths.push_back(path + to_string(node->val));
	}
};