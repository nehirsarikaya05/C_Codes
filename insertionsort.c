#include <stdio.h>
#define SIZE 5
void insertionSort(int a[], int b);
int main(void){
  int arr[] = {85, 56, 78, 14, 46}; 
  insertionSort(arr, SIZE);
  for (size_t a=0; a<SIZE; a++){
    printf("%d ", arr[a]);
  }
  printf("\n");
}
/*
  85 56 78 14 46
  85 85 78 14 46  -> 56 key
  56 85 78 14 46
  56 85 85 14 46  -> 76 key
  56 76 85 14 46 
  56 76 85 85 46  -> 14 key
  56 76 76 85 46
  56 56 76 85 46
  14 56 76 85 46
  14 56 76 85 85 -> 46 key
  14 56 76 76 85
  14 56 56 76 85
  14 46 56 76 85
*/
void insertionSort(int a[], int b){  
  for (int i=1; i<b; i++){
    int key = a[i];
    int j = i - 1; 
    while(j >= 0 && a[j]>key){     
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
  }
}