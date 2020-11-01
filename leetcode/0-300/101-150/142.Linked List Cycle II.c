typedef struct MyLinkedList {
  int val;
  struct MyLinkedList * next;
} MyLinkedList;


struct ListNode *detectCycle(struct ListNode *head) {
  if(!head || !head->next) 
    return NULL;
  
  struct ListNode *p1 = head, *p2 = head;
  while(p2 && p2->next){
    p1 = p1->next;
    p2 = p2->next->next;
    if(p2 == p1){
      p1 = head;
      while(p1 != p2){
          p1 = p1->next;
          p2 = p2->next;
      }
      return p1;
    }
  }

  return NULL;
}
