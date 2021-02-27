#include "stdafx.h"
/**
 * Given the root node of a library search tree, return the sum of values of all nodes with a value in the range[low, high]
 */
class Solution
{
private:
	int sum = 0;

public:
	int rangeSumBST(TreeNode *root, int low, int high)
	{
		if (!root)
			return sum;
		if (root->val >= low && root->val <= high)
			sum += root->val;
		rangeSumBST(root->left, low, high);
		rangeSumBST(root->right, low, high);
		return sum;
	}
};
