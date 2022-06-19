#include <stdio.h>

int p[11]={0,1,4,5,7,9,11,13,13,15,16}, result[11], cuts[11];

int memoizedCutRod(int n) {
  int max=0;
  if (n==0)
    return 0;
  if (result[n]!=0)
    return result[n];
  for (int i = 1; i <= n; i++) {
    if(max<p[i]+memoizedCutRod(n-i)){
      max=p[i]+memoizedCutRod(n-i);
      cuts[i]++;
    }
  }
  result[n]=max;
  return max;
}

int main(void) {
  int num=10;
  printf("The maximum price is %d\n", memoizedCutRod(num));
  cuts[1]-=2*(num/2);
  for(int i=10; i>=1; i--){
    if(cuts[i]!=0)
      printf("A rod is cut %d times with length %d\n", cuts[i], i);
  }
  return 0;
}
