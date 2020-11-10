// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return vector<int>{};
        if (root->children.size() == 0) return vector<int>{root->val};
        
        vector<int> list;
        list.push_back(root->val);
        for (Node* child: root->children) {
            vector<int> children = preorder(child);
            for(int subchild: children) {
                list.push_back(subchild);
            }
        }
        
        return list;
    }
};