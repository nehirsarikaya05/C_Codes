#include <stdio.h>
int main(void){
  int entry;
  for (int i=1; i<40; i++){
    for (int j=1; j<=i && i%2==1; j++){
      printf("*");
    }
    if (i%2) printf("\n");
  }
}
