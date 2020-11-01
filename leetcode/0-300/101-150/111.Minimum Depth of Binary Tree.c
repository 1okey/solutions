// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path 
// from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

// Example:

// Given binary tree [3,9,20,null,null,15,7],


/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    
    if(!root->left) return 1 + minDepth(root->right);
    if(!root->right) return 1 + minDepth(root->left);
    
    int l = 1 + minDepth(root->left);
    int r = 1 + minDepth(root->right);
    
    return l > r ? r : l;
}