#include <stdio.h>
int main(void){
    int number=0;
    int total;
    while (number != -1){
        printf("Please enter any number: ");
        scanf("%d", &number);
        total=0;
        for (int i=1; i<number; i++){
            if (number%i == 0){
              total += i;
            }
        }
        if (number == total){
          printf("The number %d is a perfect number.\n", number);
        }
        else if (number != -1){
          printf("The number %d is not a perfect number.\n", number);
        }
    }
}
