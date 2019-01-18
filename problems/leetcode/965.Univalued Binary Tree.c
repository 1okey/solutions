// A binary tree is univalued if every node in the tree has the same value.
//
// Return true if and only if the given tree is univalued.
//
//
// Example 1:
//
//
// Input: [1,1,1,1,1,null,1]
// Output: true
// Example 2:
//
//
// Input: [2,2,2,5,2]
// Output: false
// 
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

 
bool isUnivalTree(struct TreeNode* root) {
  bool left =  !root->left  || root->val == root->left->val  && isUnivalTree(root->left);
  bool right = !root->right || root->val == root->right->val && isUnivalTree(root->right);
  return left && right;
}

