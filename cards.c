#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TYPE 4
#define NUM 13 
#define TOTAL 52
void shuffle(unsigned int deck[][NUM]);
int main(void){
  char *symbols[4] = {"♥", "♦", "♣", "♠"};
  char *names[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10","jack", "queen", "king"};
  srand(time(NULL));
  unsigned int arr[TYPE][NUM] = {0};
  shuffle(arr);
  for (size_t i=0; i<TOTAL; i++){
    for (size_t j=0; j<TYPE; j++){
      for (size_t k=0; k<NUM; k++){
        if (arr[j][k] == i){
          printf("%s %s\n", symbols[j], names[k]);
        }
      }
    }
  }
}
void shuffle(unsigned int deck[][NUM]){
  for (size_t i = 0; i < TOTAL; i++){
    size_t row;
    size_t column;
    do{
      row = rand() % TYPE;
      column = rand() % NUM;
    }while(deck[row][column] != 0); /// rastgele bir satır sütun seçer
    deck[row][column] = i;
  }
}
