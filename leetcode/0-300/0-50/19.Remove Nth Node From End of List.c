typedef struct MyLinkedList {
  int val;
  struct MyLinkedList * next;
} MyLinkedList;


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  if(!head ||(!head->next && n == 1))
    return NULL;

  struct ListNode *target = head, *shift = head, *prev = head;
  int i = 1;
  while(shift && shift->next){
    if(i < n) {
      shift = shift->next;
      ++i;
      continue;
    }
      
    prev = target;
    target = target->next;
    shift = shift->next;
  }
  
  if(target == head){
    head = head->next;
  } else if(target->next){
    prev->next = target->next;
  } else if(!target->next) {
    prev->next = NULL;
  }

  return head;
}