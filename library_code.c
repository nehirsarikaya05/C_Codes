#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct book{
  int id;
  char title[50];
  char author[30];
  int year;
  float rating;
};
typedef struct book Book;
float updateFile();
int main(void){
  char input[20];
  Book library[5] = {
    {1255, "1984", "George Orwell", 1949, 4.8},
    {1256, "Dune", "Frank Herbert", 1965, 4.7},
    {1257, "The Hobbit", "J.R.R. Tolkien", 1937, 4.6},
    {1258, "Neuromancer", "William Gibson", 1984, 4.5},
    {1259, "Brave New World", "Aldous Huxley", 1932, 4.4}
  };
  FILE *cfPtr;
  cfPtr = fopen("library.bin", "wb");
  if (cfPtr == NULL){
    printf("File could not be opened.");
    return 0;
  }
  for (int i = 0; i<5; i++){
    fwrite(&library[i], sizeof(Book), 1, cfPtr);
  }
  printf("Files were created successfuly.\n");
  fclose(cfPtr);
  float rating = updateFile();
  Book temp;
  library[2].rating = rating;
  for (int i=4; i>=0; i--){  
    for (int j=0; j<i; j++){ 
      if (strcmp(library[j+1].title, library[j].title) < 0){
        temp = library[j+1];
        library[j+1] = library[j];
        library[j] = temp;
      }
    }
  }
  fgets(input, 19, stdin);
  input[strcspn(input, "\n")] = '\0';
  for (int a=0; a<5; a++){
     printf("%d %s %s %d %.2f\n", library[a].id, library[a].title, library[a].author, library[a].year, library[a].rating);
  }
  for (int a=0; a<5; a++){
    if (strstr(library[a].title, input) != NULL){
      printf("Book related with word: %d %s %s %d %.2f\n", library[a].id, library[a].title, library[a].author, library[a].year, library[a].rating);
    }
  }
}
float updateFile(){
  int count = 0;
  int index = 2;
  char *s1 = malloc(sizeof(char)*64);
  char year[4] = "";
  Book data[5] = {0, "", "", 0, 0.0};
  FILE *p = fopen("library.bin", "rb+");
  if (p == NULL){
    printf("File could not be opened.");
    return 0;
  }
  fseek(p, sizeof(Book)*2, SEEK_SET);
  fread(&data[2], sizeof(Book), 1, p);
  printf("Current data at 3: %d %s %s %d %.2f\n", data[2].id, data[2].title, data[2].author, data[2].year, data[2].rating);
  printf("Rating will be 4.9.\n");
  data[2].rating = 4.9;
  fseek(p, sizeof(Book)*2, SEEK_SET);
  fwrite(&data[2], sizeof(Book), 1, p);
  rewind(p);
  fread(&data[0], sizeof(Book), 1, p);
  while (!feof(p)){
    strcpy(s1, "[");
    sprintf(year, "%d", data[count].year);
    strncat(s1, year, 4);
    strcat(s1, "] ");
    strcat(s1, data[count].title);
    strcat(s1, " - ");
    strcat(s1, data[count].author);
    printf("%s ", s1);
    printf("%.2f\n", data[count].rating);
    count++;
    fread(&data[count], sizeof(Book), 1, p);
  }
  rewind(p);
  free(s1);
  fclose(p);
  return data[2].rating;
}


