#include <stdio.h>
#include <stdlib.h>
struct stackNode {
  int data;
  struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr; 
void push(StackNodePtr *topPtr, int info);
void printStack(StackNodePtr currentPtr); /// just pointer
int isEmpty(StackNodePtr topPtr);
int pop(StackNodePtr *topPtr);
int main(void){
  StackNode *top = malloc(sizeof(StackNode));
  top -> data = 0;
  top -> nextPtr = NULL;
  int count = 0;
  int c = 0;
  int d = 0;
  int del = 0;
  puts("MENU _ _ _ _ _ Exit(E) / Add(A) / Delete(D)");
  while ((c = getchar()) != 'E'){
    switch(c){
      case 'A':
        count++;
        if (count == 1) scanf("%d", &(top->data));
        else{
          scanf("%d", &d);
          push(&top, d);
        }
        break;
      case 'D':
        if (isEmpty(top)){
          del = pop(&top);
          printf("%d deleted.\n", del);
        }
        break;
    }
  }
  printStack(top);
}
void push(StackNodePtr *topPtr, int info){
  StackNodePtr *current = topPtr;
  StackNode *add = (StackNode *)(malloc(sizeof(StackNode)));
  if (add != NULL){
    add -> data = info;
    add -> nextPtr = *current; 
    *topPtr = add;   /// topPtr = &add FALSE !!!!!
  }
}
void printStack(StackNodePtr currentPtr){
  StackNodePtr current = currentPtr;
  while (current != NULL){
    printf("%d -> ", current->data);
    current = current -> nextPtr;
  }
  printf(" NULL\n");
}
int isEmpty(StackNodePtr topPtr){
  if (topPtr != NULL) return 1;
  else return 0;
}
int pop(StackNodePtr *topPtr){
  int data = 0;      
  StackNodePtr tempPtr = *topPtr;   
  *topPtr = (*topPtr)->nextPtr;  ///topPtr switchs and changes on main function
  data = tempPtr->data;
  free(tempPtr);
  return data;
}
