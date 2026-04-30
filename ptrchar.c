#include <stdio.h>
int main(void){
    char colour[] = "blue";
    char *ptr = colour;
    puts("These program represents pointer-char relations:");
    printf("colour      %s\n", colour); ///'blue'
    printf("ptr         %p\n", ptr);  ///ADDRESS
    printf("*ptr        %d\n", *ptr); //ASCII value
    printf("&colour     %p\n", &colour); ///ADDRESS
    printf("colour[0]   %c\n", colour[0]); ///'b'
}