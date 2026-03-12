#include <stdio.h>
int fibonacci(long long int x, long long int y, int s);
int main(void){
  int step;
  printf("Lutfen gormek istediginiz fibonacci sayisi adedini giriniz: ");
  scanf("%d", &step);
  fibonacci(0, 1, step);
  printf("\n");
}
int fibonacci(long long int x, long long int y, int s){
    long long int sum;
    if (s > 0){
      printf("%lld " , x);
      sum = x + y;
      fibonacci(y, sum, s-1);
      return 0;
    }
    return 0;
}
