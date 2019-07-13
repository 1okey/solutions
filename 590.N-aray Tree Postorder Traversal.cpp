#include <vector>
#include <iostream>

using std::vector;

static const int opt = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 1;
}();

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    vector<int> nodes;
public:
    void buildorder(Node* root) {
        if(!root) return;
        
        if(root->children.size() > 0) {
            for(auto* node: root->children) {
                buildorder(node);
            }
            nodes.push_back(root->val);
        }
        else nodes.push_back(root->val); 
    }
    
    vector<int> postorder(Node* root) {
        buildorder(root);    
        return nodes;
    }
};