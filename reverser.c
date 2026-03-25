#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
int bsort(int num);
int main(void){
  srand(time(NULL));
  puts("Rastgele 1-4 basamakli bir sayi olusturuyorum...");
  sleep(2);
  int a = rand() % 10000;
  printf("Olusturdugum sayi -> %d\n", a);
  bsort(a);
}
int bsort(int num){
  int b1, b2, b3, b4;
  b1 = num/1000;
  b2 = (num % 1000)/100;
  b3 = (num % 100)/10;
  b4 = num % 10;
  int arr[4] = {b1, b2, b3, b4};
  for (size_t i=3; i>0; i--){
    for (size_t j=0; j<i; j++){
      int temp;
      temp = arr[j];
      if (arr[j] > arr[j+1]){
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  printf("Bu sayinin basamaklarinin sirali hali-> ");
  for (size_t k=0; k<4; k++){
    printf("%d", arr[k]);
  }
  printf("\n");
}

