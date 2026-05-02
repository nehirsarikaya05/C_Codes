#include <stdio.h>
#include <string.h>
int main(void){
  char str1[6] = "nehir";
  char str2[10];
  fgets(str2, 10, stdin);
  str2[strcspn(str2, "\n")] = 0;
  printf("%s\n", str1);
  if ((strcmp(str1, str2) > 0)) printf("Your entry is bigger. (A-Z)\n"); 
  if ((strcmp(str1, str2)) < 0) printf("Your entry is smaller. (A-Z)\n");
  if ((strcmp(str1, str2)) == 0) printf("Our entries are same!\n");
}