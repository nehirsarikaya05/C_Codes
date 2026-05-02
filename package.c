#include <stdio.h>
#define SIZE 20
int main(void){
  char name[SIZE];
  char name2[SIZE];
  int age=0;
  int age2=0;
  char tupple[SIZE*3];
  printf("Enter your name:"); 
  scanf("%19s", name);
  printf("Enter your age:");
  scanf("%d", &age);
  sprintf(tupple, "%s is %d years old.", name, age);
  printf("%s\n", tupple);
  sscanf(tupple, "%s is %d years old.", name2, &age2);
  printf("%s\n", name2);
  printf("%d\n", age2);
}