
// https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* ptr = head;
    
    DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
    while(ptr) {
        if (ptr->data >= data) {
            if (!ptr->prev) {
                node->next = ptr;
                ptr->prev = node;
                head = node;
                break;
            }
            
            DoublyLinkedListNode* tmp = ptr->prev;
            tmp->next = node;
            node->prev = tmp;
            node->next = ptr;
            ptr->prev = node;
            return head;
        }
        if (ptr->data < data && !ptr->next) {
            ptr->next = node;
            node->prev = ptr;
            break;
        }
        ptr = ptr->next;
    }
    
    return head;
}