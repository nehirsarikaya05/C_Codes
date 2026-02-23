#include <stdio.h>
int main(void){
  for (int i=1; i <= 50; ++i){ 
    int flag = 0;
    for (int j=1; j<i; ++j){ 
      if(i%j == 0 && j!=1){
        flag = 1;
      }
    }
    flag | (i==1) ? printf("%d ben asal degilim.\n", i):printf("%d ben asalım.\n", i);
  }
}

