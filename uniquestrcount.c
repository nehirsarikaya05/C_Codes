#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 30
#define SIZE2 200
int main(void){
  char set[SIZE][SIZE];
  char *input;
  int count = 0;
  input = (char *)(malloc(sizeof(char)*SIZE2));
  fgets(input, SIZE, stdin);
  input[strcspn(input,"\n")] = 0;
  char *piece = strtok(input, " ");
  while ((piece != NULL) && count < SIZE){
    int flag = 1;
    for (int j=0; j<count; j++){
      if (strcasecmp(set[j], piece) == 0){
        flag = 0;
        break;
      }
    }
    if (flag){
      strcpy(set[count], piece);
      count++;
    }
    piece = strtok(NULL, " ");
  }
  free(input);
  printf("%d\n", count);
}
