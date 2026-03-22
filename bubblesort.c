#include <stdio.h>
#define SIZE 10
int main(void){
  int arr[10] = {42, 15, 8, 93, 27, 61, 4, 55, 19, 72};
  int temp = 0;
  for (int i=SIZE-1; i>=0; i--){  //// 9,8,7,6,5,4,3,2,1,0
    for (size_t j=0; j<i; j++){ //// if i=9 0-8, else if i=8 0-7...
      temp = arr[j]; //// do not lose small indexed value               
      if (temp > arr[j+1]){  //// if left bigger than right
        arr[j] = arr[j+1];  //// left is right
        arr[j+1] = temp;  /// right is left
      }
     }
  }
  for (size_t k=0; k<SIZE; k++){
    printf("%d\n", arr[k]);
  }
}



