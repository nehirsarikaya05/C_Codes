#include <stdio.h>
int main(void){
  int start=0; //initialize values 
  int end=-1;
  int first;
  int second;
  int third;
  //////
  while (end <= start){
    printf("Please enter starting number: ");
    scanf("%d", &start);
    printf("Please enter ending number: ");
    scanf("%d", &end);
  }
  //////
  printf("These are the armstrong number in your interval: \n");
  
  for (int i=start; i <= end; i++){
    
    ////////
    
    if((100 <= i) && (i<= 999))
    {
      first = (int) i%100; //956 --> 56
      first = (int) first%10; ///56 ---> 6
      second = (int) (i%100); ///956 ---> 56
      second = (int) (second/10); /// 56/10 ---> 5
      third = (int) (i/100); ///956 ---> 9
      if (((first*first*first) + (second*second*second) + (third*third*third)) == i){
        printf("%d\n", i);
      }
    
    }
    }
}
