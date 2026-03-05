#include <stdio.h>
int main(void){
  int entry;
  printf("Please enter an integer: ");
  scanf("%d", &entry);
  for (int i=1; i<entry; i++){
    for (int j=1; j<=i && i%2==1; j++){
      printf("*");
    }
    if (i%2) printf("\n");
  }
}
