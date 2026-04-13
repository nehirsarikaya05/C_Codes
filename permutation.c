#include <stdio.h>
void permute(int arr[], int start, int n);
void swap(int arr[], int i, int j);
int main(void){
  int array[3] = {7, 1, 2};    
  permute(array, 0, 3);
}
void permute(int arr[], int start, int n){
  if (n == start){
    for (size_t i=0; i<n; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
  else{
    for (size_t i=start; i<n; i++){ 
      swap(arr, start, i);  
      permute(arr, start+1, n);
      swap(arr, start, i);
    }
  }
}
void swap(int arr[], int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
