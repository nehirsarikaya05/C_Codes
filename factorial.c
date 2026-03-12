#include <stdio.h>
long int recursion(int x);
int main(void){
  int num;
  printf("Please enter an integer number: ");
  scanf("%d", &num);
  recursion(num);
}
long int recursion(int x){
  if (x > 0){
    x = x*recursion(x-1);
    printf("%d\n", x);
    return x;
  }
  else{
    return 1;
  }
}



