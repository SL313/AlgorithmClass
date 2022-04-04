#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int list[9] = { 12, 34, 37, 45, 57, 82, 99, 120, 134 };
	int low = 0, high = 8, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (list[mid] == 120) {
			printf("The index of 120 is %d", mid);
			return 0;
		}
		else if (list[mid] > 120) high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}
