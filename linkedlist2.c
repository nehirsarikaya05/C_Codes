#include <stdio.h>
#include <stdlib.h>
struct node{ 
  int data;
  struct node *nextptr;
};
typedef struct node Node;
void insert(Node **p, int n);
void print(Node *p);
Node *new(void);
int main(void){
  Node *n1 = NULL;
  int d = 0;
  while (d != -1){
    scanf("%d", &d);
    switch(d){
      case 1:{
        int n = 0;
        scanf("%d", &n);
        insert(&n1,n);
        break;
      }
    }
  }
  print(n1);
}
void insert(Node **p, int n){
  Node *add = new();
  add->data = n;
  Node *current = *p;
  Node *prev = NULL;
  while (current != NULL && (current->data < n)){
    prev = current;
    current = current->nextptr;
  }
  if (prev == NULL){
    add->nextptr = *p;
    *p = add;
  }
  else{
    prev->nextptr = add;
    add->nextptr = current;
  }
}
Node *new(void){
  Node *p = (Node *)malloc(sizeof(Node));
  if (p != NULL){
    p->data = 0;
    p->nextptr = NULL;
  }
  return p;
}
void print(Node *p){
  Node *current = p;
  while(current != NULL){
    printf("%d ", current->data);
    current = current -> nextptr;
  }
}
