#include <vector>
#include <iostream>
#include <unordered_set>

using std::cout;
using std::vector;
using std::unordered_set;

struct Node {
    Node(int val): val(val), next(nullptr) {}
    int val;
    Node* next;
};

void remove_duplicates(Node* head) {
    Node* ptr = head;
    Node* prev = nullptr;

    unordered_set<int> vals;
    while(ptr) {
        if(vals.find(ptr->val) != vals.end()) {
            prev->next = ptr->next;
        } else {
            vals.insert(ptr->val);
            prev = ptr;
        }
        ptr = ptr->next;
    }
}

Node* create_list_from_vector(const vector<int>& v)
{
    Node* head = new Node(v.front());
    Node* ptr = head;

    for(int i = 1; i < v.size(); ++i) {
        ptr->next = new Node(v[i]);
        ptr = ptr->next;
    }

    return head;
}

void print_list(Node* head) {
    Node* ptr = head;
    while(ptr) {
        cout << ptr->val << ' ';
        ptr = ptr->next;
    }
    cout << '\n';
}


int main(){
    Node* head = create_list_from_vector({3,7,3,1,7,6,9,6,4});

    remove_duplicates(head);

    print_list(head);
}