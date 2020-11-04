/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* ptr = head;
    --position;
    
    while(ptr && position != 0)
    {
        --position;
        ptr = ptr->next;
    }
    
    SinglyLinkedListNode* tmp = ptr->next;
    ptr->next = new SinglyLinkedListNode(data);
    ptr->next->next = tmp;
    
    return head;
}