#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!q && !p) return true;
    if((!q && p || q && !p) || q->val != p->val) return false;
           
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right) &&
           q->val == p->val;
}

