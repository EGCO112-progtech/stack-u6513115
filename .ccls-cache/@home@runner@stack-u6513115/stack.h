
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
  NodePtr top;
  int size;
} Stack;

typedef Stack *StackPtr;
void pushs(StackPtr s, int x) {
  Node *new_node = (NodePtr)malloc(sizeof(Node));
  if (new_node) {
    new_node->data = x;
    new_node->nextPtr = s->top;
    s->top = new_node;
    s->size++;
  }
}

int pops(StackPtr s) {
  NodePtr t = s->top;
  if (t != NULL) {       // if(t)
    int value = t->data; //(*top)->data
    s->top = t->nextPtr; //(*top)->nextPtr
    s->size--;
    free(t);
    return value;
  }
  printf("Empty Stack\n");
  return 0;
}
void pop_all(StackPtr s)//เอา pop ออก จน size เป็น 0
{
  while(s->size>0){
    printf("%d\n",pops(s));
  }
}
#endif
