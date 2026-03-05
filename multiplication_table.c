#include <stdio.h>
int main(void){
    int result=0;
    int num1;
    int num2;
    printf("Lutfen sayi giriniz: ");
    scanf("%d", &num1);
    printf("Lutfen sayi giriniz: ");
    scanf("%d", &num2);
    for (int i=1; i<=num1; i++){
        for (int j=1; j<=num2; j++){
            result = i*j;
            printf("%d x %d = %d\t", i, j, result);
        }
        printf("\n");
    }
}