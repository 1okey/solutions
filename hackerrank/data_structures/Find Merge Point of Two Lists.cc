// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head1 || !head2)
        return 0;
        
    SinglyLinkedListNode* ptr1 = head1, *ptr2 = head2;
    
    while (ptr1 != ptr2) {
        ptr1 = !ptr1 ? head2 : ptr1->next; 
        ptr2 = !ptr2 ? head1 : ptr2->next;        
    }
    
    return ptr1->data;
}
