#include <stdio.h>
void display(int a);
int main(void){
    display(57);
    display(10);
    display(57 & 10);
    printf("\n");
    display(20);
    display(62863);
    display(20|62863);
    printf("\n");
    display(40);
    display(~40);
    printf("\n");
    display(2367);
    display(876);
    display(876^2367);
}
void display(int a){
    int mask = 1 << 31;
    for (int i=1; i<=32; i++){
        if (!(a&mask)) printf("0");
        else printf("1");
        if (!(i%8)) printf(" ");
        a <<= 1;
    }
    printf("\n");
}