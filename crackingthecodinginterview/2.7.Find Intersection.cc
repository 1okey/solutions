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

Node* find_intersection(Node* lhs, Node* rhs) {
    Node* l_ptr = lhs;
    Node* r_ptr = rhs;

    while(l_ptr != r_ptr) {
        l_ptr = l_ptr->next ? l_ptr->next : rhs;
        r_ptr = r_ptr->next ? r_ptr->next : lhs;
    }

    return l_ptr;
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
        Node* lhs = create_list_from_vector({2,3,2});
        Node* rhs = create_list_from_vector({6,9});
        Node* tail = create_list_from_vector({7,1,8});
        
        Node* l_ptr = lhs;
        while(l_ptr->next) {
            l_ptr = l_ptr->next;
        }        
        
        Node* r_ptr = rhs;
        while(r_ptr->next) {
            r_ptr = r_ptr->next;
        }

        r_ptr->next = tail;
        l_ptr->next = tail;

        assert(find_intersection(lhs, rhs) == tail);
    }

    {
        Node* lhs = create_list_from_vector({2,3,2});
        Node* rhs = create_list_from_vector({6,9,2});
        Node* tail = create_list_from_vector({1,8});
        
        Node* l_ptr = lhs;
        while(l_ptr->next) {
            l_ptr = l_ptr->next;
        }        
        
        Node* r_ptr = rhs;
        while(r_ptr->next) {
            r_ptr = r_ptr->next;
        }
        
        r_ptr->next = tail;
        l_ptr->next = tail;

        Node* actual = find_intersection(lhs, rhs);

        assert(actual == tail);
    }

}