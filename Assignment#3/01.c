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

void insert(list* array, int pre, int num){ //pre번째에 값을 삽입
  list* newList = (list*)malloc(sizeof(list));
  newList->data = num;
  if(pre<1){
    printf("ERROR! 1번째부터 값을 삽입할 수 있습니다.\n");
    return;
  }
  else if(array==NULL){ //list가 비어있을 때
    newList->node=NULL;
    array=newList;
  }
  else if(pre==1){ //이전노드가 없을 때
    newList->node=array->node;
    array->node=newList;
    printf("값이 맨 앞에 추가되었습니다.\n");
  }
  else{ //중간에 값 insert
    for(int i=0; i<pre-1; i++){
      array=array->node;
    }
    newList->node=array->node;
    array->node=newList;
    printf("값이 %d번째에 추가되었습니다.\n", pre);
  }
  // newList->node = pre->node;
  // pre->node = newList;
}

void traverse(list* array) {
  printf("현재 list >> ");
  for(list* i=array->node; i!=NULL; i=i->node)
    printf("%d ", i->data);
  printf("\n------------------------------------------------------\n");
}

void remove(list* array, int num){
  list* temp = array->node;
  if(array==NULL){
    printf("ERROR! list가 비어있습니다.\n");
    return;
  }
  else if(array->data==num){
    array=array->node;
    printf("값 %d이 삭제되었습니다.\n", num);
  }
  else{
    while(temp->node!=NULL){
      if(temp->node->data==num){
        temp->node=temp->node->node;
        printf("값 %d이 삭제되었습니다.\n", num);
        return;
      }
      temp=temp->node;
    }
    printf("값 %d을 list에서 찾을 수 없습니다.\n", num);
  }
}

list* reverse(list* array){
  list *temp1, *temp2, *temp3;
  list* result = (list*)malloc(sizeof(list));

  temp1=array;
  temp2=NULL;

  temp1=temp1->node;
  while(temp1!=NULL){
    temp3=temp2;
    temp2=temp1;
    temp1=temp1->node;
    temp2->node = temp3;
  }
  result->data = temp2->data;
  result->node=temp2->node;
  temp2->node=result;
  
  printf("list를 역순으로 출력합니다.\n");
  return temp2;
}

int main(void) {
  int newNum;
  list* result = (list*)malloc(sizeof(list));
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    newNum = rand() % 1000 + 1;
    append(result, newNum);
  }
  printf("Generate a linked list of size 10\n"); //초기값 10개가 들어간 list
  traverse(result);

  insert(result,0,313); //0번째에 값 insert 시도 시 ERROR
  traverse(result);
  
  insert(result,1,313); //맨앞에 insert
  traverse(result);

  insert(result,5,0); //5번째에 값 '0' insert
  traverse(result);

  remove(result,10000); //값 '10000'이 list에 존재하지 않아 remove 할 수 없을 때
  traverse(result);

  remove(result, 0); //값 '0' remove
  traverse(result);

  result=reverse(result);
  traverse(result); //reverse 하여 list 출력

  result=reverse(result);
  traverse(result); //두 번 reverse 하였을 때 정상적으로 출력
  
  return 0;
}
