#include <stdio.h>
#include <stdlib.h>
int main(void){
  int size = 0;
  char *ptr;
  puts("Basic string read.");
  scanf("%d\n", &size);
  ptr = (char *)(malloc(sizeof(char)*size));
  if (ptr != NULL){
    fgets(ptr, size, stdin);
    printf("%s\n", ptr);
  }
}