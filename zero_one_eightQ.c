#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8
void printArray(int arr[][SIZE]);
int solve(int arr[][SIZE], int row);
int isSafe(int arr[][SIZE], int row, int col);
int main(void){
  int arr[SIZE][SIZE] = {0};
  printArray(arr);
  printf("\n");
  solve(arr, 0);
  printArray(arr);
}
void printArray(int arr[][SIZE]){
  for (size_t i=0; i<SIZE; i++){
    for (size_t j=0; j<SIZE; j++){
      printf("%d  ", arr[i][j]);
    }
    printf("\n");
  }
}
int isSafe(int arr[][SIZE], int row, int col){
  for (int i=0; i<col; i++){
    if (arr[row][i] == 1){
      return 0;
    }
  }
  for (int j=0; j<row; j++){
    if(arr[j][col] == 1){
      return 0;
    }
  }
  for (int a=row, b=col; b >= 0 && a >= 0; b--, a--){
    if(arr[a][b] == 1){
      return 0;
    }
  }
  for (int k=row, q=col; q >= 0 && k<SIZE; q--, k++){
    if(arr[k][q] == 1){
      return 0;
    }
  }
  return 1;
}
int solve(int arr[][SIZE], int row){
  if (row == SIZE){
    return 1;
  }
  else{
    for (int i=0; i<SIZE; i++){
      if (isSafe(arr, row, i)){
        arr[row][i] = 1;
        if (solve(arr, row+1)){
          return 1;
        }
        arr[row][i] = 0;
      }
    }
    return 0;
  }
}
