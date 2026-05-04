#include <stdio.h>
#include <string.h>
#define SIZE 20
int main(void){
  char dest[SIZE] = "apple";
  char str1[SIZE] = "application";
  int value = memcmp(dest, str1, sizeof(char)*3);
  int value2 = memcmp(dest, str1, sizeof(str1));
  printf("%d\n%d\n", value, value2);  ///0 and negative value
}