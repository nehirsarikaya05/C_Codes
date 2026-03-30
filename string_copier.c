#include <stdio.h>
void stringCop(char *s1, char *s2);
void stringCop2(char *s1, char *s2);
int main(void){
  char string1[] = "Copy_my_String";
  char string2[15];
  char string3[15];
  stringCop(string1, string2);
  stringCop(string1, string3);
  printf("%s\n", string2);
  printf("%s\n", string3);
}
void stringCop(char *s1, char *s2){
  for (size_t i=0; (s2[i] = s1[i]) != '\0' ;i++){
    ;
  }
}
void stringCop2(char *s1, char *s2){
  for (; (*s2 = *s1) != '\0'; ++s1, ++s2){
    ;
  }
}

