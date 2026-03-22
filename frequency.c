#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FREQ 13
#define NUM 500
int main(void){
  srand(time(NULL));
  int x=0;
  int y=0;
  int arr[NUM];
  int freq[FREQ] = {0}; 
  for (size_t i=0; i<NUM; i++){
    x = rand()%6 + 1;
    y = rand()%6 + 1;
    arr[i] = x + y;
  }
  for (size_t j=0; j<NUM; j++){
    ++freq[arr[j]];
  }
  for (size_t k=1; k<FREQ; k++){
    printf("%zu\t%d\n", k, freq[k]);
  }
}
