#include "linkedlist.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  if(!l1)
    return l2;
  if(!l2)
    return l1;
  if(!l1 && !l2)
    return NULL;

  struct ListNode *merged = l1, *current = l1;
  struct ListNode *merged_head = merged;
  while(l1 && l2){
    if(current == l1){
      current = l2;
      l1 = l1->next;
    } else if (current == l2){
      current = l1;
      l2 = l2->next;
    }
    merged->next = current;
    merged = merged->next;
  }
  
  return merged_head;
}