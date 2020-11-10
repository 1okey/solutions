/* https://www.hackerrank.com/challenges/tree-preorder-traversal/problem
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

void preOrder(Node *root) {
    if (!root) return;
    
    cout << root->data << ' ';
    
    preOrder(root->left);
    preOrder(root->right);
}
