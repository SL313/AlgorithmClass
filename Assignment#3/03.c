#include <stdio.h>

int check;
void checkTree(int arr[]){
  int root, left, right;
  check=1;
  for(int i=0; i<3; i++){
    root=arr[i];
    left=arr[i*2+1];
    right=arr[i*2+2];
    if(left=='null' || right=='null') continue;
    else{
      if(left>=root || right<=root){
        check=0;
        break;
      }
    }
  }
}

int main(void){
  int array[]={8, 3, 9, 'null', 'null', 4, 7};
  checkTree(array);
  if(check) printf("The following binary tree is a valid BST");
  else printf("The following binary tree is an unvalid BST");
}
