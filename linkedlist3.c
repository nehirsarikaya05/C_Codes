#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book {
  char title[100];
  int year;
  int score;
  struct Book *next;
};
typedef struct Book Book;
typedef struct Book *BookPtr;
void insertBook(BookPtr *ptr, char *title, int year, int score);
void printBooks(BookPtr p);
int main(void){
  Book *bookList = NULL;
  insertBook(&bookList, "Dune", 1965, 92);
  insertBook(&bookList, "Hyperion", 1989, 95);
  insertBook(&bookList, "Neuromancer", 1984, 88);
  insertBook(&bookList, "Dune", 1965, 92);
  insertBook(&bookList, "The C Programming Language", 1978, 98);
  insertBook(&bookList, "Linear Algebra Done Right", 1995, 85);
  insertBook(&bookList, "SystemVerilog for Design", 2006, 91);
  insertBook(&bookList, "Radiohead: A Visual History", 2024, 75);
  insertBook(&bookList, "Opeth: Palingenesis", 2011, 88);
  printBooks(bookList);
}
void insertBook(BookPtr *ptr, char *title, int year, int score){
  Book *new = (Book *) malloc(sizeof(Book));
  if (new == NULL){
    return;
  }
  strcpy(new->title, title);
  new->year = year;
  new->score = score;
  new->next = NULL;
  if ((*ptr) == NULL){
    (*ptr) = new;
  }
  else if ((*ptr)->year < year){
    BookPtr current = *ptr;
    BookPtr prev = *ptr;
    while ((current != NULL) && (current->year < year)){
      prev = current;
      current = current -> next;
    }
    prev->next = new;
    new->next = current;
  }
  else if ((*ptr)->year >= year){
    BookPtr temp = *ptr;
    (*ptr) = new;
    (*ptr)->next = temp; 
  }
}
void printBooks(BookPtr p){
  BookPtr current = p;
  while (current!=NULL){
    printf("%s %d %d\n", current->title, current->year, current->score);
    current = current -> next;
  }
  printf("\n");
}
