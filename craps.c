#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sayi_secme();
int main(void){
    int my_point=0;
    int tur=0;
    srand(time(NULL)); // o anın saatini seed olarak seçtik
    int zar_numarasi = sayi_secme();
    switch(zar_numarasi){
      case 7: case 11:
        printf("KAZANDINIZ!!!!!\n");
        break;
      case 2: case 3: case 12:
        printf("Kaybettiniz...\n");
        break;
      default:
        my_point = zar_numarasi;
        printf("Hedef sayi -> %d\n", my_point);
        printf("Oyun devam ediyor...\n\n");
        break;
    }
    while (my_point != 0){
      zar_numarasi = sayi_secme();
      if (zar_numarasi == my_point){
        printf("KAZANDINIZ!!!\n");
        break;
      }
      if (zar_numarasi == 7){
        printf("Kaybettiniz...\n");
        break;
      }
      else printf("Oyun devam ediyor...\n\n");
    }
}
int sayi_secme(){
  int num1;
  int num2;
  num1 = 1 + rand() % 6; //bir sayının 6ya bölümünden kalan 0-5 arasıdır, +1
  num2 = 1 + rand() % 6;
  printf("Attiginiz ilk zar -> %d\n", num1);
  printf("Attiginiz ikinci zar -> %d\n", num2); 
  printf("TOPLAM -> %d\n", num1+num2); 
  return num1+num2;
}
