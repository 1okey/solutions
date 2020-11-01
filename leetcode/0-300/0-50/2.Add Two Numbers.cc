/**
    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();        

        ListNode* l1_ptr = l1;
        ListNode* l2_ptr = l2;
        ListNode* l3_ptr = l3;
        
        int rest = 0;
        while(l1_ptr != nullptr && l2_ptr != nullptr) {
            l3_ptr->val = (l1_ptr->val + l2_ptr->val + rest) % 10;
            rest = (l1_ptr->val + l2_ptr->val + rest) / 10;
            l1_ptr = l1_ptr->next;
            l2_ptr = l2_ptr->next;
            if (l1_ptr || l2_ptr) {
                l3_ptr->next = new ListNode();
                l3_ptr = l3_ptr->next;
            }
        }
        
        ListNode* tail = nullptr;
        
        if (l1_ptr != nullptr) {
            tail = l1_ptr;
        } else if (l2_ptr != nullptr) {
            tail = l2_ptr;
        }
        
        while(tail != nullptr) {
            l3_ptr->val = (tail->val + rest) % 10;
            rest = (tail->val + rest) / 10;
            tail = tail->next;
            if (tail) {
                l3_ptr->next = new ListNode();
                l3_ptr = l3_ptr->next;
            }
        }
        
        if (rest != 0) {
            l3_ptr->next = new ListNode(rest);
        }
        
        return l3;
    }
};