#include <stdio.h>
#include <string.h>
#define SIZE 50
int main(void){
  char str[SIZE] = "germany,italy,france,china";
  char *piece = strtok(str, ",");
  while (piece != NULL){
    printf("%s\n", piece);
    piece = strtok(NULL, ",");
  }
}