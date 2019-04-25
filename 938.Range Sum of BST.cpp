struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isInRange(int val, int l, int r){
    return l <= val && val <= r;
}

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        if(!root)  return 0;
        
        if(isInRange(root->val, L, R)) 
            return root->val + 
                   rangeSumBST(root->left, L, R) +
                   rangeSumBST(root->right, L, R); 
        
        return rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R);
    }
};