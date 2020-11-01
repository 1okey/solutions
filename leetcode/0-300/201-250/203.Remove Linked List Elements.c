typedef struct MyLinkedList {
  int val;
  struct MyLinkedList * next;
} MyLinkedList;


struct ListNode* removeElements(struct ListNode* head, int val) {
  if(!head) 
    return NULL;
  
  struct ListNode* prev = head, *current = head, *next = head;
  
  while(prev && current && current->next) {
    prev = current;
    current = current->next;
    
    if(prev->val == val){
      prev->next = current->next;
      prev->val = current->val;
      current = prev;
      continue;
    }
    
    if(current->val == val){
      prev->next = current->next;
      current = prev;
      continue;
    }
  }
  
  if(head == prev && !prev->next && prev->val == val)
    head = NULL;
  
  
  return head;
}

// BEST / COMPACT solution below

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *ptr = head, *pre = &dummy; 
    while (ptr) {
        if (ptr->val == val) {
            pre->next = ptr->next;
            free(ptr);
            ptr = pre->next;
        } else {
            pre = ptr;
            ptr = ptr->next;
        }
    }
    
    return dummy.next;
}