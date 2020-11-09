// https://www.hackerrank.com/challenges/reverse-a-linked-list/problem

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if (!head->next) return head;
    
    SinglyLinkedListNode* tail = reverse(head->next);
    
    head->next->next = head;
    
    head->next = nullptr;
    
    return tail;
}
