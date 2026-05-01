#include <stdio.h>
#include <stdlib.h>
void reverse(const char * const ptr);
int main(void){
  int size = 0;
  char *ptr;
  printf("Choose size: "); 
  scanf("%d\n", &size);
  ptr = (char *)(malloc(sizeof(char)*size));
  if (ptr != NULL){
    fgets(ptr, size, stdin);
    reverse(ptr);
    free(ptr);
  }
}
void reverse(const char * const ptr){
  if ('\0' == ptr[0]){
    return;
  }
  else{
    reverse(ptr+1);
    putchar(ptr[0]);
  }
}