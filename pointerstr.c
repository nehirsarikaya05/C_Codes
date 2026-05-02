#include <stdio.h>
#include <stdlib.h>
int main(void){
  int size = 0;
  int i = 0;
  int j = 0;
  char *ptr;
  scanf("%d\n", &size);
  ptr = (char *)(malloc(sizeof(char)*size));
  fgets(ptr, size, stdin);
  while (ptr[i] != '\0'){
    printf("%c", ptr[i]);
    i++;
  }
  while(*(ptr+j) != '\0'){
    printf("%c", *(ptr+j)); //dereferencing
    j++;
  }
  while(*ptr != '\0'){
    printf("%c", *ptr);
    ptr++;
  }
  free(ptr);
} 