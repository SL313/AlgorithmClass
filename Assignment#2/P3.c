#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int x = 3, y = 2, z = 5;
	printf("%d\n", ((x > y) ? x : y) > z ? ((y > x) ? x : y) : z);
	return 0;
}
