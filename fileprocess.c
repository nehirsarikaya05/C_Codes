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
struct Info{
  int day;
  int month;
  int year;
  char client[S];
  long int id;
};
typedef struct Info Info; 
void read(FILE **p);
void write(FILE **p);
void clear(FILE **p);
void view(FILE **p);
int main(void){
  FILE *p = fopen("list.dat", "rb+");
  int option = 0;
  if (p==NULL){
    puts("File could not be opened.");
    return 0;
  }
  printf("1 for read, 2 for write, 3 clear list, 4 access to all list(-1 exit): ");
  scanf("%d", &option);
  while (option != -1){
    switch(option){
      case 1:
        read(&p);
        printf("You have exited reading mode.\n");
        printf("1 for read, 2 for write, 3 clear list, 4 access to all list(-1 exit): ");
        scanf("%d", &option);
        break;
      case 2:
        write(&p);
        printf("You have exited writing mode.\n");
        printf("1 for read, 2 for write, 3 clear list, 4 access to all list(-1 exit): ");
        scanf("%d", &option);
        break;
      case 3:
        clear(&p);
        printf("You have exited clear mode.\n");
        printf("1 for read, 2 for write, 3 clear list, 4 access to all list(-1 exit): ");
        scanf("%d", &option);
        break;
      case 4:
        view(&p);
        printf("You have exited view mode.\n");
        printf("1 for read, 2 for write, 3 clear list, 4 access to all list(-1 exit): ");
        scanf("%d", &option);
        break;
      case -1:
        printf("Exit.\n");
        break;
      default:
        printf("Wrong entry. Please enter digits 1 or 2!\n");
        scanf("%d", &option);
        break;
    }
  }
  fclose(p);
}
void read(FILE **p){
  Info read;
  int order = 0;
  puts("Enter -1 to exit.");
  printf("Enter the order that you want to access: ");
  scanf("%d", &order);
  while(order != -1){
    fseek(*p, (order - 1) * sizeof(Info),SEEK_SET);
    fread(&read, sizeof(Info), 1, *p);
    fprintf(stdout, "%d-%d-%d %s -> %ld\n", read.day, read.month, read.year, read.client, read.id);
    printf("Enter the order that you want to access: ");
    scanf("%d", &order);
  }
}
void write(FILE **p){
  Info write;
  int order = 0;
  puts("Enter -1 to exit.");
  printf("Enter the order that you want to write: ");
  scanf("%d", &order);
  while (order != -1){
    printf("Day:");
    scanf("%d", &write.day);
    printf("Month:");
    scanf("%d", &write.month);
    printf("Year:");
    scanf("%d", &write.year);
    printf("Name:");
    scanf("%s", write.client);
    printf("ID:");
    scanf("%ld", &write.id);
    fseek(*p, (order - 1) * sizeof(Info), SEEK_SET);
    fwrite(&write, sizeof(Info), 1, *p);
    printf("Enter the order that you want to write: ");
    scanf("%d", &order);
  }
}
void clear(FILE **p){
  rewind(*p);
  int choice = 0;
  Info empty = {0, 0, 0, "", 0};
  printf("If you press 102, all your data will be deleted.\n");
  scanf("%d", &choice);
  if (choice == 102){
    for (size_t i=0; i<100; i++){
      fwrite(&empty, sizeof(Info), 1, *p);
    }
    printf("Deleted.\n");
  }
  else{
    return;
  }
}
void view(FILE **p){
  Info read;
  int count = 0;
  rewind(*p);
  fread(&read, sizeof(Info), 1, *p);
  while (!feof(*p)){
    count++;
    printf("%d ", count);
    fprintf(stdout, "%d-%d-%d %s -> %ld\n", read.day, read.month, read.year, read.client, read.id);
    fread(&read, sizeof(Info), 1, *p);
  }
}
