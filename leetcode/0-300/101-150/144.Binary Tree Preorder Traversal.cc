// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> leaves;
        vector<int> solution;
        TreeNode* ptr = root;
        
        while(ptr || leaves.size() > 0) {
            if (ptr) {
                solution.push_back(ptr->val);
                leaves.push_back(ptr);
                ptr = ptr->left;
            } else {
                TreeNode* back = leaves.back();
                ptr = back->right;
                leaves.pop_back();
            }
        }
        
        return solution;
    }
};