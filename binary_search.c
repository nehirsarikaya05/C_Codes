#include <stdio.h>
#define SIZE 10
size_t binarySearch(int a[], size_t high, size_t low, int target);
void printHeader();
void printArray(int a[], size_t mid, size_t high, size_t low);
int main(void){
  int target=0;
  int arr[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  scanf("%d", &target);
  printHeader();
  binarySearch(arr, SIZE-1, 0, target);
}
void printHeader(){
  for (size_t i=0; i<SIZE; i++){
    printf("  %zu  ", i);
  }
  printf("\n");
  for (int i=0; i<25; i++){
    printf(" _");
  }
  printf("\n");
}
void printArray(int a[], size_t mid, size_t high, size_t low){
  for (size_t i=0; i<SIZE; i++){
    if (i < low || i > high){
      printf("%s", "     ");
    }
    else if (i == mid){
      printf("  %d*  ", a[i]);
    }
    else{
      printf(" %d  ", a[i]);
    }
  }
  printf("\n");
}
size_t binarySearch(int a[], size_t high, size_t low, int target){
  while (high >= low){
    size_t mid=0;
    mid = (high + low)/2;
    printArray(a, mid, high, low);
    if (target == a[mid]){
      return mid;
    }
    else if (target < a[mid]){
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return -1;
}
