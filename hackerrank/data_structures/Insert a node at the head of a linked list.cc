// https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    
    if (!llist) {
        return node;
    }
    
    node->next = llist;
    return node;
}