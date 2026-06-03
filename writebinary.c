#include <stdio.h>
#define S 200
/* FILE FUNCTIONS 
  getchar -> fgetc
  putchar -> fputc('a', stdout);
  FILE *p -> file pointer
  fopen(".txt", "w");
  fclose(p);
  feof(stdin) -> when EOF turns 1
  fprintf(stdout, format, ...); stdout -> pointer
  fscanf(stdin, format, ...);
  rewind(ptr); -> turning for starting point
  fwrite(ptr of data, sizeof, count, ptr of file);
  fread(ptr of data, sizeof, count, ptr of file);
  r -> read, w -> write, a -> append
  r+ -> read and update
  a+ -> create, read, update
  rb, wb, ab -> binary format
  SEEK_SET -> from 0
  SEEK_CUR -> from current
  SEEK_END -> from end
  fseek(fptr, sizeof, SEEK_);
*/
struct clientData{
  unsigned int id;
  char name[S];
  int month;
  int day;
};
typedef struct clientData ClientData;
int main(void){
  FILE *ptr = fopen("client.dat", "wb");
  if (ptr==NULL){
    puts("File not could be opened.");
    return 0;
  }
  ClientData empty = {0, "", 0, 0};
  for (size_t i=0; i<100; i++){
    fwrite(&empty, sizeof(ClientData), 1, ptr);
  }
  fclose(ptr);
}
