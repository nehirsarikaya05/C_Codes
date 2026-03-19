#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dice();
int print(int x);
int main(void){
  srand(time(NULL));
  dice();
}
int dice(){
  int count=0;
  int x;
  int y;
  int c1=0;
  int c2=0;
  int c3=0;
  int c4=0;
  int c5=0;
  int c6=0;
  int c7=0;
  int c8=0;
  int c9=0;
  int c10=0;
  int c11=0;
  int c12=0;
  while (count < 500){
    count ++;
    x = 1 + rand() % 6;
    y = 1 + rand() % 6;
    switch (x+y){
      case 1:
        c1++;
        break;
      case 2:
        c2++;
        break;
      case 3:
        c3++;
        break;
      case 4:
        c4++;
        break;
      case 5:
        c5++;
        break;
      case 6:
        c6++;
        break;
      case 7:
        c7++;
        break;
      case 8:
        c8++;
        break;
      case 9:
        c9++;
        break;
      case 10:
        c10++;
        break;
      case 11:
        c11++;
        break;
      case 12:
        c12++;
        break;
    }
  }
  print(c1);
  print(c2);
  print(c3);
  print(c4);
  print(c5);
  print(c6);
  print(c7);
  print(c8);
  print(c9);
  print(c10);
  print(c11);
  print(c12);
}
int print(int x){
  static int a=1;
  printf("%d", a);
  a++;
  for (int i=1; i<=x; i++){
    printf("*");
  }
  printf("\n");
}
