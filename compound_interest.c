#include <stdio.h>
#include <math.h>
int main(void){
    int money;
    int year;
    float result;
    float interest = 0.05;
    printf("Please enter your money:");
    scanf("%d", &money);
    printf("Please enter year:");
    scanf("%d", &year);
    for (int i=1; i<=year; i++){
      result = 0;
      result = money * pow(1+interest,i);
      printf("%d. yıldaki paraniz -> %.1f\n", i, result);
    }
}
