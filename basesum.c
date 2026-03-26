#include <stdio.h>
int baseSum(long long int num, int sum);
int main(void){
    long long int a=0;
    scanf("%lld", &a);
    printf("%d\n",baseSum(a,0));
}
int baseSum(long long int num, int sum){
    if (num > 0){
        sum += num%10;
        return baseSum(num/10, sum);
    }
    else{
        return sum;
    }
}