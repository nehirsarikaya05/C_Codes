#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Card{
    char *face;
    char *type;
};
typedef struct Card card;
void create(card deck[], char *t[], char *f[]);
void shuffle(card deck[]);
int main(void){
    srand(time(NULL));
    card mycard[52];
    char *types[] = {"A", "2", "3", "4",
    "5", "6", "7", "8", "9", "10",
    "J", "Q", "K"};
    char *faces[] = {"♠", "♥",
    "♦", "♣"};
    create(mycard, types, faces);
    shuffle(mycard);
}
void create(card deck[], char *t[], char *f[]){
    for (int i=0; i<52; i++){
        deck[i].face = t[i%13];
        deck[i].type = f[i/13];
    }
}
void shuffle(card deck[]){
    for (int i=0; i<52; i++){
        size_t j = rand() % 52;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    for (int j=0; j<52; j++){
        printf("%s %s\n",
        deck[j].face, deck[j].type);
    }
}