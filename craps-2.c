#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rollDice(void);
int pointRoll(int point);
int main(void){
    srand(time(NULL));
    int first = rollDice();
    switch(first){
        case 2: case 3: case 12:
            printf("You lost.\n");
            break;
        case 11: case 7:
            printf("You win.\n");
            break;
        default:
            pointRoll(first);   
            break;
    }
}
int rollDice(void){
    int a = 0;
    int b = 0;
    a = (rand() % 6) + 1;
    b = (rand() % 6) + 1;
    printf("%d\n", a+b); 
    return a+b;
}
int pointRoll(int point){
    int other = rollDice();
    if (other == point){
        printf("You win.\n");
    }
    else if (other == 7){
        printf("You lost.\n");
    }
    else{
        return pointRoll(point);
    }
}