/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if (position == 0) {
        return head->next ? head->next : nullptr;
    }
    
    SinglyLinkedListNode* ptr = head;
    --position;
    while(ptr->next && position != 0) {
        --position;
        ptr = ptr->next;
    }
    
    if (ptr->next && ptr->next->next) {
        SinglyLinkedListNode* tmp = ptr->next->next;
        ptr->next = tmp;
    } else {
        ptr->next = nullptr;
    }
    
    return head;
}