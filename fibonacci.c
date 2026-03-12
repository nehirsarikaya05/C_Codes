#include <stdio.h>
int recursion(int n1, int n2);
int main(void){
  int num1=1;
  int num2=2;
  printf("%d ", num1);
  printf("%d ", num1);
  printf("%d ", num2);
  recursion(num1, num2);
}
int recursion(int n1, int n2){
  if (n1 + n2<1000){
    int x;
    x = n1 + n2;
    printf("%d ", x);
    recursion(n2, x);
  }
  else{
  }
}
