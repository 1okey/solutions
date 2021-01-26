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

Node* sum_lists(Node* lhs, Node* rhs) {
    int sum = 0;
    int carry = 0;

    Node* ptr = new Node(0);
    Node* head = ptr;
    Node* prev = ptr;

    while(lhs && rhs) {
        sum = lhs->val + rhs->val;
        carry = sum / 10;
        sum %= 10;

        ptr->val += sum;
        ptr->next = new Node(carry);
        prev = ptr;
        ptr = ptr->next;

        lhs = lhs->next;
        rhs = rhs->next;
    }

    while(lhs) {
        prev = ptr;
        ptr->val += lhs->val;
        ptr->next = new Node(carry);
        ptr = ptr->next;
        lhs = lhs->next;
    }

    while(rhs) {
        prev = ptr;
        ptr->val += rhs->val;
        ptr->next = new Node(carry);
        ptr = ptr->next;
        rhs = rhs->next;
    }

    if (ptr->val == 0) {
        delete ptr;
        prev->next = nullptr;
    }

    return head;
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
        Node* rhs = create_list_from_vector({6,9,1});
        Node* expected = create_list_from_vector({8,2,4});
        Node* sum = sum_lists(lhs, rhs);

        assert(lists_equal(sum, expected));
    }

    {
        Node* lhs = create_list_from_vector({2,3,2,1});
        Node* rhs = create_list_from_vector({6,9,1});
        Node* expected = create_list_from_vector({8,2,4,1});
        Node* sum = sum_lists(lhs, rhs);

        assert(lists_equal(sum, expected));
    }

}