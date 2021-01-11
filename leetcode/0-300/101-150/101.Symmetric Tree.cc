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
private:
    int lhs = 0;
    int rhs = 0;
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        return areBranchesSymmetrical(root->left, root->right);
    }
    
    bool areBranchesSymmetrical(TreeNode* lhs, TreeNode* rhs) {
        if (!lhs && !rhs) return true;
        
        if (!lhs || !rhs) return false;
        
        return lhs->val == rhs->val &&
            (areBranchesSymmetrical(lhs->left, rhs->right) 
            && areBranchesSymmetrical(lhs->right, rhs->left));
    }
};