#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linkedList {
  int data;
  struct linkedList* node;
} list;

void append(list* array, int num) {
  list* newList = (list*)malloc(sizeof(list));
  newList->data = num;
  newList->node = NULL;
  if (array == NULL) //list가 비어있을 때
    array = newList;
  else {
    list* temp = array;
    while (temp->node != NULL)
      temp= temp->node;
    temp->node = newList;
  }
}

void traverse(list* array) {
  printf("현재 list >> ");
  for(list* i=array->node; i!=NULL; i=i->node)
    printf("%d ", i->data);
  printf("\n------------------------------------------------------\n");
}

void deleteCopy(list* array) {
  int check;
  while(array!=NULL){
    check=array->data;
    list* temp = array;
    while(temp->node!=NULL){
      if(temp->node->data==check)
        temp->node=temp->node->node;
      else
        temp=temp->node;
    }
    array=array->node;
  }
}

int main(void) {
  int newNum;
  list* result = (list*)malloc(sizeof(list));
  srand(time(NULL));
  for (int i = 0; i < 20; i++) {
    newNum = rand() % 50 + 1;
    append(result, newNum);
  }
  printf("Generate a linked list of size 20 whose elements are from 1 to 50\n"); //초기값 10개가 들어간 list
  traverse(result);
  deleteCopy(result);
  printf("중복값을 제외하고 난 list\n");
  traverse(result);
  
}
