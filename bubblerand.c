#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 80
void sortArray(int a[], size_t b);
int main(void){
  int arr[SIZE];
  int num=0;
  srand(time(NULL));
  for (size_t i=0; i<SIZE; i++){
    num = (rand() % 100) + 1;
    arr[i] = num;
  }
  puts("Unsorted Array:");
  for (size_t j=0; j<SIZE; j++){
    printf("%d ", arr[j]);
  }
  printf("\n");
  sortArray(arr, SIZE);
  puts("Sorted Array:");
  for (size_t k=0; k<SIZE; k++){
    printf("%d ", arr[k]);
  }
  printf("\n"); 
}
void sortArray(int a[], size_t b){
  for (size_t i=b-1; i>0; i--){  
    for (size_t j=0; j<i; j++){
      if (a[j] > a[j+1]){ 
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
        }
    }
  }
}
