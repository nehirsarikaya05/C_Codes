#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct {
    char name[32];
    int grades[5]; 
    float average;
} Student;
void calc_average(Student *s);
void top_student(Student *arr, int n, Student **result);
int filter_above(Student *arr, int n, float threshold, Student *out);
void print(Student *s);
int main(void){
  srand(time(NULL));
  Student four[4];
  Student tresh[4];
  Student *p = four;  // p points student 1 
  Student *t;
  Student *p2 = tresh;
  strcpy(p->name, "James");
  strcpy((p+1)->name, "Julia");
  strcpy((p+2)->name, "Robert");
  strcpy((p+3)->name, "Katy");
  for (int i=0; i<4; i++){
    for (int j=0; j<5; j++){
      four[i].grades[j] = (rand() % 60) + 40;
      
   }
   four[i].average = 0; 
   calc_average(p+i);
   print(p+i);
  }
  top_student(p,4,&t);
  print(t);
  int num = filter_above(p, 4, 70.00, tresh);
  for (int j=0; j<num; j++){
    print(p2+j);
  }
}
void calc_average(Student *s){
  int total = 0;
  for (int i=0; i<5; i++){
    total += s->grades[i];
  }
  s->average = (float)total/5.0;
}
void top_student(Student *arr, int n, Student **result){
  int count = 0;
  float temp = 0;
  int index = 0;
  while (count<n){
    if (temp < (arr+count)->average){
      temp = (arr+count)->average;
      index = count;
    }
    count++;
  }
  *result = &arr[index]; 
}
void print(Student *s){
  printf("Name: %s\n", s->name);
  printf("Grades: %d %d %d %d %d\n", s->grades[0], s->grades[1], s->grades[2], s->grades[3], s->grades[4]);
  printf("Average: %.3f\n", s->average);
  printf("\n");
}
int filter_above(Student *arr, int n, float threshold, Student *out){
  int count = 0;
  for (int i=0; i<n; i++){
    if ((arr+i)->average > threshold){
      out[count] = arr[i]; 
      count++;
    }
  }
  return count;
}
