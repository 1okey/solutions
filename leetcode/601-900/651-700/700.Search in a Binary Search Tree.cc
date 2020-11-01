/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static int asyncx = [](){                  
  std::ios::sync_with_stdio(false);        
  std::cin.tie(nullptr);                   
  std::cout.tie(nullptr);                  
  return 0;                                
}();                                       

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root->val == val) return root;
        if(root->right && root->val < val) return searchBST(root->right,val);
        if(root->left && root->val > val) return searchBST(root->left,val);
        return nullptr;
    }
};
