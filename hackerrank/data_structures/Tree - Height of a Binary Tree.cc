/* https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem

class Node {
    int data;
    Node* left;
    Node* right;
};
*/

int height(Node* root, int depth = -1) {
    if (!root) return depth;
    
    ++depth;
    
    return max(height(root->left, depth),  height(root->right, depth));
}