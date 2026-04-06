#include <stdio.h>
#define SIZE 10
int solveQueen(int b[][SIZE], int col);
int isSafe(int b[][SIZE], int col, int row);
void printBoard(int board[SIZE][SIZE]);
int main(void){
  int board[SIZE][SIZE] = {0};
  solveQueen(board, 0);
  printBoard(board);
}
int solveQueen(int b[][SIZE], int col){
  if (col >= SIZE) return 1;
  for (int i=0; i<SIZE; i++){
    if (isSafe(b, col, i)){
      b[i][col] = 1;
      if (solveQueen(b, col+1) == 1){
        return 1;
      }
      else{
        b[i][col] = 0;
      }
    }
  }
  return 0;
}
int isSafe(int b[][SIZE], int col, int row){
  int i, j;
  for (i=row, j=0; j<col; j++){
    if (b[i][j] == 1) return 0; 
  }
  for (i=row-1, j=col-1; (i>=0 && j>=0); i--, j--){
    if (b[i][j] == 1) return 0;
  }
  for (i=row+1, j=col-1; (i<SIZE && j>=0); i++, j--){
    if (b[i][j] == 1) return 0;
  }
  return 1;
}
void printBoard(int board[SIZE][SIZE]) {
    printf("\n--- Cozum Tahtasi ---\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 1) {
                printf(" V "); // Vezir karakteri
            } else {
                printf(" . "); // Bos kare
            }
        }
        printf("\n"); // Her satirdan sonra alt satira gec
    }
    printf("---------------------\n");
}
