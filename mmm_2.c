#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void defineArray(int a[], size_t b);
void printArray(int a[], size_t b);
void bubbleSort(int a[], size_t b);
double average(int a[], size_t b);
void mode(int a[], size_t b);
int main(void){
  srand(time(NULL));
  int mainArray[SIZE] = {0};
  defineArray(mainArray, SIZE);
  puts("The main array is:");
  printArray(mainArray, SIZE);
  bubbleSort(mainArray, SIZE);
  printf("Average -> %.3f\n", average(mainArray, SIZE));
  printf("Median -> %.1f\n", (mainArray[SIZE/2] + mainArray[(SIZE/2)-1])/2.0);  
  mode(mainArray, SIZE);
}
void defineArray(int a[], size_t b){
  for (size_t i=0; i<b; i++){
    a[i] = (rand() % 19) + 1;   ///1-19///
  }
}
void printArray(int a[], size_t b){
  for (size_t i=0; i<b; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}
void bubbleSort(int a[], size_t b){
  for (size_t i=0; i<b; i++){
    for (size_t j=0; j<b-1; j++){
      if (a[j] > a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}
double average(int a[], size_t b){
  double total = 0;
  for (size_t i=0; i<b; i++){
    total += a[i];
  }
  total = (double)(total/b);
  return total;
}
void mode(int a[], size_t b){
  int freq[20] = {0};
  for (size_t i=0; i<b; i++){
    ++freq[(a[i])];
  }
  int big = freq[1];
  int ind = 0;
  for (size_t j=0; j<=19; j++){
    if (freq[j] > big){
      big = freq[j];
      ind = j;
    }
  }
  printf("Mode -> %d\n", ind);
}
