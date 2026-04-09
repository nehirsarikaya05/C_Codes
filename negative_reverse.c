#include <stdio.h>
#include <stdlib.h>
int main(void){   ////1 -3 2 -5 -2 4
  int n = 0;
  scanf("%d", &n);  ////6
  int *arr =(int *)malloc(n * sizeof(int));
  int *left = arr;  ///arr[0]
  int *right = arr + n - 1;  ///arr[5]
  for (int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
    while(left < right){
      if (*left >= 0 || *right >= 0){
        if (*left >= 0) left++;
        if (*right >= 0) right--;
      }
      else{
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
      }
    }
  for (int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}
