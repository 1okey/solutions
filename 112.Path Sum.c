// Given a binary tree and a sum, determine if the tree has a root-to-leaf 
// path such that adding up all the values along the path equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \      \
// 7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

#include <stdbool.h>

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPath(struct TreeNode* root, int sum, int acc) {
    if(!root) return false;
    
    acc += root->val;
    
    if (!root->left && !root->right) return acc == sum;
    if (!root->left) return hasPath(root->right, sum, acc);
    if (!root->right) return hasPath(root->left, sum, acc);
        
    return hasPath(root->right, sum, acc) || 
           hasPath(root->left, sum, acc);   
}

bool hasPathSum(struct TreeNode* root, int sum) {
    return hasPath(root, sum, 0);
}