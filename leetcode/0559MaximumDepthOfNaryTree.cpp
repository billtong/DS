#include "stdafx.h"

/**
* Given a n-ary tree. find its maximum depth
* The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
*/

class Solution 
{
private:
    int max_depth;
public:
    Solution(): max_depth(0) {}
    int maxDepth(Node* root) 
    {
        if (!root) return 0;
        dfs(root, 1);
        return max_depth;

    }

    void dfs(Node* node, int depth)
    {
        if (node)
        {
            if (node->children.size() > 0)
            {
                for (auto c : node->children)
                {
                    dfs(c, depth + 1);
                }
            }
            else
            {
                if (max_depth < depth) max_depth = depth;
            }
        }
    }

};



class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};