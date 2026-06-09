#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int isCross(char *p, char word[50]);
int aWhere(char *s);
bool isTest(char *s);
int main(void){
  int count = 0;
  char *new = malloc(sizeof(char)*80);
  char *s = malloc(sizeof(char)*80);
  char cword[50] = "";
  fgets(s, 80, stdin);
  s[strcspn(s, "\n")] = '\0';
  int value = aWhere(s);
  bool istest = isTest(s);
  scanf("%s", cword);
  char *p = strtok(s, " ");
  while (p != NULL){
    if (isCross(p, cword)){
      strcat(new, "*** ");
    }
    else{
      strcat(new, p);
      strcat(new, " ");
    }
    p = strtok(NULL, " ");
    count++;
  }
  printf("%s\n", new);
  if (value) printf("%d\n", value);
  if (istest) printf("YES\n");
}
int isCross(char *p, char word[50]){
  if (strcmp(p, word) == 0) return 1;
  else return 0;
}
int aWhere(char *s){
  if (strchr(s, 'a') == NULL){
    return 0;
  }
  else{
    char *p1 = strchr(s, 'a');
    char *p2 = strrchr(s, 'a');
    return (p2-p1);
  }
}
bool isTest(char *s){
  if (strstr(s, "test") != 0){
    return 1;
  }
  else{
    return 0;
  }
}
