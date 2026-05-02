#include <stdio.h>
#include <string.h>
int main(void){
  char str1[30] = "Let's combine";
  char str2[30] = " strings!";
  char str3[15];
  strncat(str1, str2, 29);
  printf("%s\n", str1);
  strncpy(str3, str1, 14);
  printf("%s\n", str3);
}