#include "linkedlist.h"

MyLinkedList* myLinkedListCreate() {
  MyLinkedList * node = (struct MyLinkedList*) malloc(sizeof(MyLinkedList));
  node->val = -1;
  node->next = NULL;
  return node;
}  

int myLinkedListGet(MyLinkedList* obj, int i) {
  while(i-- > 0){
    obj = obj->next;
    if(obj == NULL || (obj->next == NULL && i >= 1)) return -1;
  }
  return obj->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  if(obj-> val < 0){
    obj->val = val;
  } else {
    MyLinkedList * head = myLinkedListCreate();
    head->next = obj->next;
    head->val = obj->val;
    obj->next = head;
    obj->val = val;
  }
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
  if(obj->val == -1){
    obj->val = val;
  } else {
    MyLinkedList * tail = myLinkedListCreate();
    MyLinkedList * node = obj;
    while(node->next != NULL){
      node = node->next;
    }
    node->next = tail;
    tail->val = val;
  }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index == 0){
      myLinkedListAddAtHead(obj, val);
      return;
    }

    MyLinkedList *node = obj;
    int i = index - 1;  
    while(i-- > 0){
      node = node->next;
      if(node->next == NULL && i >= 1) return;
    }
  
    if(node->val == -1) return;
    
    MyLinkedList * new_node = myLinkedListCreate();
    new_node->val = val;
  
    if(node->next == NULL){
      node->next = new_node;
    } else {
      new_node->next = node->next;
      node->next = new_node;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index == 0){
      MyLinkedList * next = obj->next;
      obj->val = next->val;
      obj->next = next->next;
      free(next);
      return;
    } 

    MyLinkedList *node = obj;
    int i = index - 1;  
    while(i-- > 0){
      node = node->next;
      if(node->next == NULL && i >= 1) return;
    }
  
    if(node->next == NULL){
      return;
    } else {
      MyLinkedList * target = node->next;
      if(target->next == NULL) {
        node->next = NULL;
        free(target);
      } else {
        node->next = target->next;
        free(target);
      }
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList * prev = obj;
    MyLinkedList * cur = obj->next;
    while(cur != NULL){
      free(prev);
      prev = cur;
      cur = cur->next;
    }
    free(prev);
}
