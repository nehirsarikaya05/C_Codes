#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct songNode {
  char songName[200];
  struct songNode *nextPtr;
};
typedef struct songNode SongNode;
typedef SongNode *SongNodePtr;
void appendSong(SongNodePtr *sPtr, const char *newSong);
void playNext(SongNodePtr *sPtr);
int removeSong(SongNodePtr *sPtr, const char *targetSong);
void printPlaylist(SongNodePtr currentPtr);
int main(void){
  const char *s1 = "muse-muscle_museum";
  const char *s2 = "radiohead-all_i_need";
  const char *s3 = "katatonia-deliberation";
  const char *s4 = "the_cure-lovesong";
  const char *s5 = "soundgarden-black_hole_sun";
  SongNode *n1 = NULL;
  playNext(&n1);
  appendSong(&n1, s1);
  appendSong(&n1, s2);
  appendSong(&n1, s3);
  appendSong(&n1, s4);
  appendSong(&n1, s5);
  playNext(&n1);
  playNext(&n1);
  printf("%d\n", removeSong(&n1, s4));
  printPlaylist(n1);
}
void appendSong(SongNodePtr *sPtr, const char *newSong){
  SongNode *new = malloc(sizeof(SongNode));
  if (new == NULL) return; /// for safety
  strcpy(new->songName, newSong); 
  new->nextPtr = NULL;
  if ((*sPtr) == NULL){
    *sPtr = new;
  }
  else{
    SongNodePtr current = *sPtr;
    while (current->nextPtr != NULL){
      current = current->nextPtr; 
    }
    current->nextPtr = new;
  }
}
void playNext(SongNodePtr *sPtr){
  SongNodePtr tempPtr = *sPtr;
  if ((*sPtr) == NULL){
    printf("List is empty.\n");  
  }
  else{
    printf("Playing: %s\n", tempPtr->songName);
    *sPtr = (*sPtr)->nextPtr;
  }
  free(tempPtr);
}
int removeSong(SongNodePtr *sPtr, const char *targetSong){
  SongNodePtr prev, current = *sPtr;
  int flag = 0;
  while ((strcmp(current->songName, targetSong) != 0) && current != NULL){
    prev = current;
    current = current -> nextPtr;
    if (strcmp(current->songName, targetSong) == 0) flag = 1;
  }
  if (flag == 1){
    SongNodePtr temp = current;
    prev->nextPtr = current->nextPtr;
    free(temp);
    return 1;
  }
  else return 0;
}
void printPlaylist(SongNodePtr currentPtr){
  while (currentPtr != NULL){
    printf("%s\n", currentPtr->songName);
    currentPtr = currentPtr->nextPtr;    
  }
}
