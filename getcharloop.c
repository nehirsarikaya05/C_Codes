#include <stdio.h>
#include <stdlib.h>
#define SIZE 50 
int main(void){
  int c;
  char string[SIZE];
  int i=0;
  while (i < SIZE && (c = getchar()) != '\n'){
    string[i] = c;
    i++;
  }
  string[i] = '\0';
  printf("%s\n", string);
} 