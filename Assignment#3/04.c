#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* leftChild;
  struct Node* rightChild;
}node;

node* insert(node* root, int num){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data=num;
  newNode->leftChild=NULL;
  newNode->rightChild=NULL;
  if(root==NULL){
    root=newNode;
    return root;
  }
  else if(num<root->data)
    root->leftChild=insert(root->leftChild, num);
  else
    root->rightChild=insert(root->rightChild, num);
  return root;
}

node* findAncestor(node* root, int n1, int n2){
  while(root!=NULL){
    if(n1<root->data && n2<root->data)
      return findAncestor(root->leftChild, n1, n2);
    else if(n1>root->data && n2>root->data)
      return findAncestor(root->rightChild, n1, n2);
    else
      return root;
  }
  return root;
}

int main(void){
  int array[]={6, 2, 8, 1, 3, 7, 9}, num1, num2;
  node* tree = (node*)malloc(sizeof(node));
  for(int i=0; i<7; i++){
    insert(tree, array[i]);
  }
  printf("Tree 배치 완료\n");
  
  printf("(1) Two inputs: ");
  scanf("%d %d", &num1, &num2);
  printf(">> The lowest common ancestor : %d\n\n", findAncestor(tree,num1,num2)->data);
  
  printf("(2) Two inputs: ");
  scanf("%d %d", &num1, &num2);
  printf(">> The lowest common ancestor : %d\n\n", findAncestor(tree,num1,num2)->data);
  
  printf("(3) Two inputs: ");
  scanf("%d %d", &num1, &num2);
  printf(">> The lowest common ancestor : %d\n\n", findAncestor(tree,num1,num2)->data);
  
  return 0;
}
