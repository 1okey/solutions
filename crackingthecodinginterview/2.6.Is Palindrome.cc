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

bool is_palindrome(Node* head) {
    Node* reversed = nullptr;
    Node* ptr = head;
    while(ptr) {
        Node* node = new Node(ptr->val);
        node->next = reversed;
        reversed = node;
        ptr = ptr->next;
    }

    while(reversed && head) {
        if (reversed->val != head->val) {
            return false;
        }

        head = head->next;
        reversed = reversed->next;
    }

    return true;
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
        assert(is_palindrome(lhs) == true);
    }
    {
        Node* lhs = create_list_from_vector({2,3,2,4});
        assert(is_palindrome(lhs) == false);
    }
}