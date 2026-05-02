#include <stdio.h>
#include <string.h>
int main(void){
  int c=0;
  char *str1 = "berlin";
  char str2[7];
  printf("Guess the city!\n");
  printf("If you want to guess whole city press X!\n");
  while ((c = getchar()) != 'X'){
    char *ptr = strchr(str1, c);
    if (ptr != NULL){
      for (int i=0; i<6; i++){
        if ((str1 + i)!=ptr){
          printf("_");
        }
        else{
          printf("%c", c);
        }
      }
      printf("\n");
    }
  }
  while (getchar() != '\n' && getchar() != EOF);
  fgets(str2, 7, stdin);
  str2[strcspn(str2, "\n")] = 0;
  if (strcmp(str1, str2) == 0){
    printf("You find!!\n");
  }
  else{
    printf("Wrong guess -> %s\n", str1);
  }
}