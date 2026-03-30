#include <stdio.h>
int main(void){
  puts("This program teachs to you Pointer Arithmetic.");
  int a[5] = {10,20,30,40,50};
  int *p = a;
  puts("This is the array a[5] = {10,20,30,40,50}");
  puts("Pointer p, points to a.");
  printf("Here is the pointer p -> %p\n", p);
  printf("By *(p+i) ");
  for (size_t i=0; i<5; i++){
    printf("%d  ", *(p+i));
  }
  printf("\n");
  printf("By *(a+i) ");
  for (size_t i=0; i<5; i++){
    printf("%d  ", *(a+i));
  }
  printf("\n");
  printf("By p[i] ");
  for (size_t i=0; i<5; i++){
    printf("%d  ", p[i]);
  }
  printf("\n");
  p += 2;
  printf("p += 2\n");
  printf("%p %d\n", p, *p);
}


