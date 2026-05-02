#include <stdio.h>
#include <string.h>
#define SIZE 50
int main(void){
  char ill[SIZE];
  char tupple[SIZE*4];
  int age = 0;
  int weight = 0;
  printf("Enter your health issue: ");
  fgets(ill, SIZE, stdin);
  ill[strcspn(ill, "\n")] = 0;
  printf("Enter your age:");
  scanf("%d", &age);
  printf("Enter your weight:");
  scanf("%d", &weight);
  sprintf(tupple, "MD John; patient is %d years old, %d kg and complaining about %s.", age, weight, ill);
  printf("%s\n", tupple);
}