#include <stdio.h>
#include <stdlib.h>
struct queueNode {
    char data;                 
    struct queueNode *nextPtr; 
};
typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;///QueueNodePtr -> pointer of struct
int isEmpty(QueueNodePtr headPtr, QueueNodePtr tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
void print(QueueNodePtr headPtr, QueueNodePtr tailPtr);
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
int main(void){
  QueueNodePtr head = NULL;
  QueueNodePtr tail = NULL;
  enqueue(&head, &tail, 'A');
  enqueue(&head, &tail, 'B');
  enqueue(&head, &tail, 'C');
  dequeue(&head, &tail);
  enqueue(&head, &tail, 'D');
  dequeue(&head, &tail);
  print(head, tail);
}
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value){
  QueueNodePtr n1 = malloc(sizeof(QueueNode));
  n1->data = value;
  n1->nextPtr = NULL;
  if (isEmpty(*headPtr, *tailPtr)){ 
    *headPtr = n1;
    *tailPtr = n1;
  }
  else{
    (*tailPtr) -> nextPtr = n1;
    *tailPtr = n1;
  }
}
void print(QueueNodePtr headPtr, QueueNodePtr tailPtr){
  QueueNodePtr current = headPtr;
  while (current != NULL){
    printf("%c -> ", current->data);
    current = current -> nextPtr;
  }
  if (current == NULL){
    printf("NULL\n");
  }
}
int isEmpty(QueueNodePtr headPtr, QueueNodePtr tailPtr){
  if ((headPtr == NULL) && (tailPtr == NULL)) return 1;
  else return 0;
}
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
  if (isEmpty(*headPtr, *tailPtr)){
    return;
  }
  else{
    QueueNodePtr p = (*headPtr) -> nextPtr;
    char c = (*headPtr)->data;
    free(*headPtr);
    *headPtr = p;
    printf("%c deleted.\n", c);
  }
  if (*headPtr == NULL) *tailPtr = NULL;
}
