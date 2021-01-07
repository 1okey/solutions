// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> leaves;
        vector<int> solution;
        TreeNode* ptr = root;
        
        while(ptr || leaves.size() > 0) {
            if (ptr) {
                // go down the left branch
                leaves.push_back(ptr);
                ptr = ptr->left;
            } 
            else {
                // nothing to the left? push the last leaf value, take last leaf and proceed
                TreeNode* back = leaves.back();
                solution.push_back(back->val);
                ptr = back->right;
                leaves.pop_back();
            }
        }
        
        return solution;
    }
};