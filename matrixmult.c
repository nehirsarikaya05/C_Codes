#include <stdio.h>
#define SIZE 3
#define SIZE2 2
#define SIZE3 1
void printArray(size_t row, size_t column, int a[row][column]);
void matrismultp(size_t p, size_t n, size_t r, int a[p][n], int b[n][r]);
int main(void){
  int arr[2][3] = {0};
  int arr1[3][1] = {0};
  puts("Bu program matris carpimi yapar.");
  printf("Lutfen 2x3 luk ilk matrisi giriniz:");
  for (size_t i=0; i<2; i++){
    for(size_t j=0; j<3; j++){
      int a=0;
      scanf("%d", &a);
      arr[i][j] = a;
    }
  }
  printf("Lutfen 3x1 lik ikinci matrisi giriniz:");
  for (size_t k=0; k<3; k++){
    for(size_t q=0; q<1; q++){
      int b=0;
      scanf("%d", &b);
      arr1[k][q] = b;
    }
  }
  puts("Ilk matris:");
  printArray(2,3, arr);
  printf("\n");
  puts("Ikinci matris:");
  printArray(3,1, arr1);
  printf("\n");
  matrismultp(2,3,1, arr, arr1);
}
void printArray(size_t row, size_t column, int a[row][column]){
  for (size_t i=0; i<row; i++){
    for (size_t j=0; j<column; j++){
      printf("[%d]", a[i][j]);
    }
    printf("\n");
  }
}
void matrismultp(size_t p, size_t n, size_t r, int a[p][n], int b[n][r]){
  int mult[SIZE2][SIZE3] = {0};
  for (size_t i=0; i<p; i++){  /// 0 1
    for (size_t j=0; j<n; j++){ /// 0 1 2
      for (size_t k=0; k<r; k++){ //0
        mult[i][k] += a[i][j]*b[j][k]; 
      }
    }
  }
  puts("Matris carpimi:");
  printArray(SIZE2, SIZE3, mult);
} 
