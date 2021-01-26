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

bool lists_equal(Node* lhs, Node* rhs)
{
    while(lhs && rhs) {
        if(lhs->val != rhs->val) {
            return false;
        }
        lhs = lhs->next;
        rhs = rhs->next;
    }

    return !lhs && !rhs;
}

void remove_from_middle(Node* node) {
    if (node->next && node->next->next) {
        Node* current = node;
        Node* next = node->next;
        current->val = next->val;
        current->next = next->next;
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
    {
        Node* list = create_list_from_vector({3,7,3,1,7,6,9,6,4});
        Node* third_node = list->next->next;
        remove_from_middle(third_node);
        print_list(list);

        assert(lists_equal(list,  create_list_from_vector({3,7,1,7,6,9,6,4})));
    }

    {
        Node* other = create_list_from_vector({3,7,3,1,7,6,9,6,4,10});
        Node* fifth = other->next->next->next->next;
        remove_from_middle(fifth);
        print_list(other);

        assert(lists_equal(other,  create_list_from_vector({3,7,3,1,6,9,6,4,10})));

        Node* second = other->next;
        remove_from_middle(second);
        print_list(other);

        assert(lists_equal(other,  create_list_from_vector({3,3,1,6,9,6,4,10})));
    }
}