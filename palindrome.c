#include <stdio.h>
#include <math.h>
int is_palindrome(long long x);
int main(void){
    long long base;
    long long top;
    printf("Please enter the base of interval that you want to search Palindrome Numbers: ");
    scanf("%lld", &base);
    printf("Please enter the top number: ");
    scanf("%lld", &top);
    for (long long i = base; i<=top; i++){
      if (is_palindrome(i)) printf("%lld\n", i);
    }
}
int is_palindrome(long long x){
    int digit=0; ///initialize numbers
    int remainder;
    long long palindrome=0;
    long long y;
    long long z;
    y = x; /// for backing up 'x'
    z = x;
    while(x != 0){
        x /= 10;  
        digit += 1;
    }
    while(y != 0){
      remainder = y%10; //// 28569 --> 9
      y /= 10; /// 2856
      digit -= 1;
      palindrome += (pow(10, digit)*remainder);
    }
    return (palindrome == z) ? 1 : 0;
}


