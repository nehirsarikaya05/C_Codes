#include <stdio.h>
struct Name{
  char *name;
  int age;
  struct Name *ptr;
};
int main(void){
  struct Name p1 = {"Bilge", 22, NULL};
  struct Name p2 = {"Nehir", 21, NULL};
  struct Name p3 = {"Pasa", 4, NULL};
  p1.ptr = &p2;
  p2.ptr = &p3;
  printf("%s\t%d\n", p1.ptr->name, p1.ptr->age);
  printf("%s\t%d\n", p1.ptr->ptr->name, p1.ptr->ptr->age);
}
