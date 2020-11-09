// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(
    SinglyLinkedListNode* head1, 
    SinglyLinkedListNode* head2
) {
    SinglyLinkedListNode* head = new SinglyLinkedListNode(head1->data);
    SinglyLinkedListNode* ptr = head;
    
    while (head1 && )
    {
        if (head1->data < head2->data) {
            ptr->next = new SinglyLinkedListNode(head1->data);
            head1 = head1->next;
        } else {
            ptr->next = new SinglyLinkedListNode(head2->data);
            head2 = head2->next;
        }
        ptr = ptr->next;
    }
    
    while (head1) {
        ptr->next = new SinglyLinkedListNode(head1->data);
        ptr = ptr->next;
        head1 = head1->next;
    }
    
    while (head2) {
        ptr->next = new SinglyLinkedListNode(head2->data);
        ptr = ptr->next;
        head2 = head2->next;
    }

    return head->next;
}

// or recursively

SinglyLinkedListNode* mergeLists(
    SinglyLinkedListNode* h1, 
    SinglyLinkedListNode* h2
) {
    if (!h1 && !h2) return nullptr;

    if (!h1) return h2;
    
    if (!h2) return h1;

    SinglyLinkedListNode *smaller;
    if (h1->data < h2->data) {
        smaller = h1;
        smaller->next = mergeLists(h1->next, h2);
    } else {
        smaller = h2;
        smaller->next = mergeLists(h1, h2->next);
    }
    
    return smaller;
}
