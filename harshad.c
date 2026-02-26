#include <stdio.h>
int main(void){
  int entry=0;
  int joker;
  int sum=0;
  printf("Please enter an integer number: ");
  scanf("%d", &entry);
  /////////////////////////
  joker = entry;
  while(entry == 0){
    printf("Please enter an integer number: ");
    scanf("%d", &entry);
    joker = entry;
    }
  while(entry > 0){
    sum += entry % 10;
    entry = entry/10;
  }
  if ((joker%sum == 0) ? printf("This is a harshad number.\n") : printf("This is not a harshad number.\n"));
  }
