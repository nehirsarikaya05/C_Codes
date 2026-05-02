#include <stdio.h>
#include <string.h>
#define SIZE 50
int main(void){
  char str2[SIZE];
  char str3[SIZE] = "Turkiye Ankara";  //15
  printf("Please enter your orders country and city:");
  fgets(str2, SIZE, stdin);
  str2[strcspn(str2, "\n")] = 0;
  size_t j = strspn(str2, str3);
  if (j >= 14) printf("We have main service.\n");
  if (8 <= j && j < 14) printf("You can take your order from Ankara.\n");
  else if (j < 8) printf("We don't have any service.\n");
}