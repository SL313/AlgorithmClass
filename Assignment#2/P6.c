#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pairSum(int arr[], int num) {
  printf("[");
  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (arr[i] + arr[j] == num)
        printf("'%d+%d' ", arr[i], arr[j]);
    }
  }
  printf("]");
}
int main(void) {
  int list[10] = {2, 4, 3, 5, 6, -2, 4, 7, 8, 9};
  pairSum(list, 7);
  return 0;
}
