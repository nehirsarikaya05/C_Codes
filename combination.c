#include <stdio.h>
int com(long long int x,long long int y,long long int p,long long int d, int c);
int main(void){
    long long int x=8;
    long long int y=3;
    long long int p=1;
    long long int d=1;
    int c=1;
    printf("Please enter the n:");
    scanf("%d", &x);
    printf("Please enter the k:");
    scanf("%d", &y);
    com(x, y, p, d, c);
}
int com(long long int x,long long int y,long long int p,long long int d, int c){
    if (c <= y){
        p *= x;
        x = x-1;
        d *= c;
        c++;
        com(x, y, p, d, c);
    }
    else{
        printf("The C(n,k) %lld.", p/d);
    }
}