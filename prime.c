#include <stdio.h>
int main(void){
  for (int i=1; i <= 500; ++i){ 
    int flag = 0;
    for (int j=1; j<i; ++j){ 
      if(i%j == 0 && j!=1){
        flag = 1;
      }
    }
    if (!(flag | (i==1))) printf("%d ben asalım.\n", i);
  }
}

