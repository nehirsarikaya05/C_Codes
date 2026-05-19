#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int data;
  struct Node *next;
}Node;
Node *create(int data);
void append(Node **head, int data);
void print_list(Node *head);
void free_list(Node **head);
int main(void){
  Node *n1 = create(5);
  append(&n1, 7);
  append(&n1, 9);
  print_list(n1);
  free_list(&n1);
}
Node *create(int data){
  Node *p = malloc(sizeof(Node));  // now it is not a dangling pointer! (segmentation fault prevention)
  p->data = data;
  p->next = NULL;
  return p;
};
void append(Node **head, int data){
  /// head -> p to p, *head -> p, head -> struct
  Node *current = *head;
  while (current->next != NULL){
    current = current->next;
  }
  current->next = create(data);
}
void print_list(Node *head){
  Node *current = head;
  while (current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }
}
void free_list(Node **head){
  Node *current = *head;
  while (current != NULL){
    Node *temp = current->next;
    free(current);
    current = temp;
  }
}
