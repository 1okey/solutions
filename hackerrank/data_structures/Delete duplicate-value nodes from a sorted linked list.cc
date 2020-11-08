// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *cur = head, *next = head;
    
    while (cur && next) {
        if (cur->data == next->data) {
            if (!next->next) {
                cur->next = nullptr;
            }
            next = next->next;
        } else {
            cur->next = next;
            cur = cur->next;
        }
    }
    

    return head;
}