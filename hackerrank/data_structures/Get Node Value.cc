// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode *cur = head, *ptr = head;
    int i = 0;
    
    while (cur)
    {
        cur = cur->next;
        if (i++ > positionFromTail) {
            ptr = ptr->next;
        }
    }
    
    return ptr->data;
}
