#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyLinkedList {
  int val;
  struct MyLinkedList * next;
} MyLinkedList;
