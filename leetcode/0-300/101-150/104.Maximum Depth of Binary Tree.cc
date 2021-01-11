// https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/535/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int left_branch = 1 + maxDepth(root->left);
        
        int right_branch = 1 + maxDepth(root->right);
        
        return max(left_branch, right_branch);
    }
};