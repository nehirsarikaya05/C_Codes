#include <stdio.h>
#define SIZE 10
float mean(int a[], size_t b);
float median(int a[1], size_t b);
int mod(int a[], size_t b);
int main(void){
  int arr[SIZE] = {8, 3, 1, 3, 4, 7, 6, 3, 6, 5}; 
  printf("The mean value is ");
  printf("%.1f.\n", mean(arr, SIZE));
  printf("The median value is ");
  printf ("%.1f.\n", median(arr, SIZE));
  printf("The mode value is ");
  printf("%d.\n", mod(arr, SIZE));
}
float mean(int a[], size_t b){
  float sum=0;
  for (size_t i=0; i<b; i++){
    sum += a[i];
  }
  sum /= b;
  return sum;
}
float median(int a[], size_t b){
  for (size_t i=b-1; i>0; i--){
    for (size_t j=0; j<i; j++){
      if (a[j] > a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
        }
    }
  }
 if (b % 2){
  float med = a[(b/2)];
  return med;
 }
 else{
  float med1 = (a[b/2] + a[(b/2)-1])/2.0;
  return med1;
 }
}
int mod(int a[], size_t b){
  int max=0;
  int ind=0;
  int freq[SIZE] = {0};
  for (size_t i=0; i<b; i++){
    ++freq[a[i]];
  }
  for (size_t j=0; j<b; j++){
    if (freq[j] > max) {
      ind = j;
      max = freq[j];
    }
  }
  return ind;
}
