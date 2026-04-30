#include <stdio.h>
#include <ctype.h>
#define SIZE 6
int main(void){
  char greeting[SIZE] = "hello";
  printf("%d\n", isalpha('A')); //random integer
  printf("%d\n", isalpha('2')); //0
  printf("%d\n", isalnum('2')); //random integer
  printf("%d\n", isalnum('/')); //0
  printf("%d\n", isdigit('7')); //random integer
  printf("%d\n", isdigit('A')); //0
  printf("%d\n", isxdigit('F')); //random integer
  printf("%d\n", isxdigit('G')); //0
  printf("%d\n", islower('a')); //random integer
  printf("%d\n", islower('A')); //0
  printf("%d\n", isupper('A')); //random integer
  printf("%d\n", isupper('a')); //0
  for (int i=0; i<SIZE; i++){
    greeting[i] = toupper(greeting[i]);   ///h->H, e->E...
  }
  printf("%s\n", greeting);
  for (int j=0; j<SIZE; j++){   //reverse
    greeting[j] = tolower(greeting[j]); ///H->h, E->e...
  }
  printf("%s\n", greeting);
  printf("%d\n", isgraph('>')); //random integer
  printf("%d\n", isgraph('\n')); // 0
}