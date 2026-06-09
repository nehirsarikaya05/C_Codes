#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///114_BUS:ROUTE-OK:1A4F|114_BUS:DROP-ENGINE:8B|999_BUS:SPEED-FAST:2C|114_BUS:DOOR-OPEN*ERR:F9|114_BUS:AC-ON:12X4//
void discreteData(char **sPtr);
int header(char *sPtr);
int payload(char *sPtr);
int main(void){
  int c = 0;
  int count = 0;
  char raw[1024] = "";
  while ((c=getchar()) != '\n'){
    raw[count] = c;
    count++;
  }
  char *p = strtok(raw, "|");
  while (p!=NULL){
    discreteData(&p);
    p = strtok(NULL, "|");
  }
}
void discreteData(char **sPtr){
  char *p = strchr(*sPtr, ':');
  if (p != NULL){
    p[0] = '\0';          
    if (header(*sPtr)){
      char *t = strchr(p+1, ':');
      if (t != NULL){
        t[0] = '\0';
        payload(p+1);
      }
    }
  }
}
int header(char *sPtr){
  if ((strcmp(sPtr, "114_BUS")) == 0){
    printf("%s\n", sPtr);
    return 1;
  }
  else return 0;
}
int payload(char *sPtr){
  size_t index = 0;
  int count = 0;
  if ((strstr(sPtr, "DROP") != 0) || (strchr(sPtr, '-')!= NULL)){
    index = strcspn(sPtr, "*?~");
    while (count != index){
      printf("%c", sPtr[count]);
      count++;
    }
    printf("\n");
    return 1;
  }
  else return 0;
}
