#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct treeNode{
  struct treeNode *leftptr;
  int data;
  struct treeNode *rightptr;
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;
void insertNode(TreeNodePtr *treePtr, int value);
void randomizeTree(TreeNodePtr *p);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
int main(void){
  srand(time(NULL));
  TreeNodePtr p1 = NULL;
  randomizeTree(&p1);
  inOrder(p1);
  printf("\n");
  preOrder(p1);
  printf("\n");
  postOrder(p1);
  printf("\n");
}
void insertNode(TreeNodePtr *treePtr, int value){
  if ((*treePtr) == NULL){
    (*treePtr) = malloc(sizeof(TreeNode));
    if ((*treePtr) == NULL) { printf("Bellek yetersiz!\n"); exit(1); }
    (*treePtr)->leftptr = NULL;
    (*treePtr)->data = value;
    (*treePtr)->rightptr = NULL;
  }
  else if((*treePtr) != NULL){
    if ((*treePtr)->data > value){
      insertNode(&((*treePtr)->leftptr), value);
    }
    else if ((*treePtr)->data < value){
      insertNode(&((*treePtr)->rightptr), value);
    }
    else{
      return;
    }
  }
}
void randomizeTree(TreeNodePtr *p){
  for (int i=0; i<40; i++){
    int data = rand() % 100;
    insertNode(p, data);
  }
}
void inOrder(TreeNodePtr treePtr){
  if (treePtr == NULL) return;
  if (treePtr != NULL){
    inOrder(treePtr->leftptr);
    printf("%d ", treePtr->data);
    inOrder(treePtr->rightptr);
  }
}
void preOrder(TreeNodePtr treePtr){
  if (treePtr == NULL) return;
  if (treePtr != NULL){
    printf("%d ", treePtr->data);
    preOrder(treePtr->leftptr);
    preOrder(treePtr->rightptr);
  }
}
void postOrder(TreeNodePtr treePtr){
  if (treePtr == NULL) return;
  if (treePtr != NULL){
    postOrder(treePtr->leftptr);
    postOrder(treePtr->rightptr);
    printf("%d ", treePtr->data);
  }
}
