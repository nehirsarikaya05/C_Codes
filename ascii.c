#include <stdio.h>
int main(void){
  int c=0;
  while((c = getchar()) != EOF){
    if (c == '\n') continue;
    printf("The character %c\n", c);
    printf("ASCII Value %d\n", c);
  }
}