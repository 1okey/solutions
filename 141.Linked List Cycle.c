#include "linkedlist.h"

bool hasCycle(struct ListNode *head) {
    if (head == 0) return false;

    struct ListNode *slow = head, *fast = head->next;
    while (fast && fast->next && fast != slow) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return fast == slow;
}