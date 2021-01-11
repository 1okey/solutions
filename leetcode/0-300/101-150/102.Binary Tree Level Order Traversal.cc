// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> solution;
        
        if (!root) {
            return solution;
        }
        
        queue<TreeNode*> lvl;
        lvl.push(root);
        
        while(!lvl.empty()) {
            vector<int> level;
            int size = lvl.size();
            
            while(size > 0) {
                TreeNode* node = lvl.front();
                lvl.pop();
                if(node->left) {
                    lvl.push(node->left);
                }
                if(node->right) {
                    lvl.push(node->right);
                }
                level.push_back(node->val);
                --size;
            }
            
            solution.emplace_back(move(level));
        }
        
        return solution;
    }
};