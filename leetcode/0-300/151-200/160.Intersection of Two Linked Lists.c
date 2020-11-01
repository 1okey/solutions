typedef struct MyLinkedList {
  int val;
  struct MyLinkedList * next;
} MyLinkedList;


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA || !headB)
      return NULL;
  
    struct ListNode *ptr_a = headA, *ptr_b = headB;
  
    while(ptr_a != ptr_b) {
      ptr_a = ptr_a == NULL ? headB : ptr_a->next;
      ptr_b = ptr_b == NULL ? headA : ptr_b->next;
    }
  
    return ptr_a;
}