#include <stdio.h>
#include <stdlib.h>
int main(void){
  puts("These program shows the working principles of stdlib functions.");
  char data[] = "56.79 is the value.";
  char *ptr1;
  printf("%p\n", ptr1); ///(nil)
  double d = strtod(data, &ptr1);
  printf("%p\n", ptr1); ////ADDRESS
  printf("%.2f\n", d); ///56.79
  printf("%s\n", ptr1); //remaining string
  char *data2 = "-3479845 is the value.";
  char *ptr2;
  long int l = strtol(data2, &ptr2, 0);
  printf("%ld\n", l);
  printf("%s\n", ptr2); ///remaining string
  char *data3 = "468685 is the value.";
  char *ptr3;
  unsigned long ul = strtoul(data3, &ptr3, 0);
  printf("%lu\n", ul);
  printf("%s\n", ptr3); //remaining string 
}