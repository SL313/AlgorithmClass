#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 100
int check(char s[]) {
	int len = 0;
	len = strlen(s);
	for (int i = 0; i <= (len - 1) / 2; i++) {
		if (s[i] != s[len - 1 - i]) {
			return 0;
			break;
		}
		return 1;
	}
}
int main(void) {
	int str[N];
	gets(str);
	if (check(str)) printf("Palindrome");
	else printf("None Palindrome");
	return 0;
}
