typedef struct MyLinkedList {
  int val;
  struct MyLinkedList * next;
} MyLinkedList;


struct ListNode* oddEvenList(struct ListNode* head) {
  if(!head)
    return NULL;
  
  struct ListNode *current = head, *prev = head, *odd_tail = head;
  int i = 2;
  while(current && current->next){
    prev = current;
    current = prev->next;

    if(i % 2  == 1){
      prev->next = current->next;
      current->next = odd_tail->next;
      odd_tail->next = current;
      odd_tail = current;
      
      current = prev;
      prev = odd_tail;
    }
    
    i++;
  }
  
  return head;
}