// https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    
    if (!head) {
        return node;
    }
    
    SinglyLinkedListNode* ptr = head;
    while(ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = node;
    return head;
}