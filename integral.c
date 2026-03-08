#include <stdio.h>
double integral(int a, int b);
int main(void){
  int base;
  int top;
  puts("This program computes integral for x square function over an interval.");
  printf("Please enter the base number:");
  scanf("%d", &base);
  printf("Please enter the top number:");  
  scanf("%d", &top);
  integral(base, top);
}
double integral(int a, int b){
  double dx;
  double real;
  double sum=0;
  dx = (b-a)*0.0001;
  for (double i=a; i<b; i+= dx){
    sum += dx*(i*i);
  }
  real = ((b*b*b)/3.0) - ((a*a*a)/3.0);
  printf("This is my approximation ---> %.3f\n", sum);
  printf("This is real value ---> %.3f\n", real);
  return sum;
}
