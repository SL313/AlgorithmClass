#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	int n, k = 1;
	scanf("%d", &n);
	while (1)
		if (pow(2, ++k) > n) break;
	printf("%d", k - 1);
	return 0;
}
