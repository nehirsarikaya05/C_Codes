#include <stdio.h>
#include <stdlib.h>
int main(void){
  char *ptr;
  char *ptr1;
  int day,month,year;
  ptr1 = (char *)(malloc(sizeof(int)*4));
  ptr = (char *)(malloc(sizeof(int)*5));
  printf("%e\n", 6.02*10000000);
  printf("%f\n", 9.16/10000000);
  printf("%o\n", 1000); 
  printf("%g\n", 6.02*1000000);
  printf("%5d\n", 123);
  printf("%9.5f\n", 12.456878715345);
  printf("%-8d%-8d\n", 1234, 4895);
  printf("%#x\n", 16);
  scanf("%5[0123456789]", ptr);
  printf("%s\n", ptr);
  scanf("%4[^0123456789]", ptr1);
  printf("%s\n", ptr1);
  scanf("%d%*c%d%*c%d\n", &day, &month, &year);
  printf("%d\n%d\n%d\n", day, month, year);
  free(ptr);
  free(ptr1);
}