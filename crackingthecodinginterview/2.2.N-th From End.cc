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

Node* get_nth_from_end(Node* head, int n) {
    Node* ptr = head;

    int size = 0;
    while(ptr) {
        ++size;
        ptr = ptr->next;
    }

    if (size <= n) {
        return head;
    }

    ptr = head;
    int index = size - n - 1;
    while(index >= 0) {
        --index;
        ptr = ptr->next;
    }

    return ptr;
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
    Node* node1 = create_list_from_vector({3,7,3,1,7,6,9,6,4});

    assert(get_nth_from_end(node1, 4)->val == 6);
    assert(get_nth_from_end(node1, 1)->val == 4);
    assert(get_nth_from_end(node1, 11)->val == 3);


    Node* node2 = create_list_from_vector({3,7,3,1,7,6,9,6,4,10});
    assert(get_nth_from_end(node2, 4)->val == 9);
    assert(get_nth_from_end(node2, 1)->val == 10);
    assert(get_nth_from_end(node2, 11)->val == 3);
}