#include <stdio.h>
#include <string.h>
#define SIZE 10
int main(void){
  char dest[SIZE] = "10 20";
  char str1[SIZE] = "30 40 50 ";
  memmove(dest, str1, 5*sizeof(char));
  printf("%s\n", dest);
  //30 40
}
