#include <stdio.h>
#define SIZE 100
int main(void){
  int a=0;
  int arr1[SIZE] = {0};
  int *read = arr1;
  int *write = arr1;
  scanf("%d", &a);
  for (int i=0; i<a; i++){
    scanf("%d", read);
    read++;
  }
  read = &arr1[0];
  while(read < arr1 + a){ // 1 2 2 3 4
    if (*read == *write){
      read++;
    }
    else{
      write++;
      *write = *read;
    }
  }
  int *p = arr1;
  while (p <= write){
    printf("%d ", *p);
    p++;
  }
} 
