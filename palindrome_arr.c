#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], size_t b);
void detectPal(int arr[], size_t b);
int main(void){
  int a = 0;
  scanf("%d", &a); 
  int *arr = (int *)malloc(a * sizeof(int));
  for (int i=0; i<a; i++){
    scanf("%d", &arr[i]);
  }
  detectPal(arr, a);
  free(arr);
}
void printArray(int arr[], size_t b){
  for (size_t i=0; i<b; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}
void detectPal(int arr[], size_t b){
  int maxLength = 0;
  int start = 0;
  int bigo = 0;
  int smallo = 0;
  for (int i=1; i<b; i++){   //// 1 2 3 4 5
    for (int j=i+1, k=i-1; (j<b) && (k>=0); ++j, --k){
      if (arr[j] == arr[k]){ 
        if (maxLength < j){
          maxLength = j;
          start = k;
        }
      }
      else{
        break;
      }
    }
    for (int j=i+1, k=i; (j<b) && (k>=0); j++, k--){
        if(arr[j] == arr[k]){
          if (bigo < j){
            bigo = j;
            smallo = k;
          }
          else{
            break;
          }
        }
    }
  }
  if ((maxLength - start) % 2 == 0 && (maxLength != 0)){
    for (size_t i=start; i<=maxLength; i++){ 
      printf("%d ", arr[i]);
    }
  }
  else{
    for (size_t i=smallo; i<=bigo; i++){ 
      printf("%d ", arr[i]);
    }
  }
  printf("\n");
}
