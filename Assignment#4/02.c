#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define min(a,b)  (a < b) ? a : b
int num1, num2, num3, num4;
int dp[10][10], temp[10][2];
int matrix1[5][3], matrix2[3][7], matrix3[7][10], tmp[3][10], result[5][10];

int solution(int num) {
    int n1, n2, tmp;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i; j++) {
            n1 = j;
            n2 = j + i;
            if (n1 == n2) dp[n1][n2] = 0;
            else {
                dp[n1][n2] = 987654321;
                for (int k = n1; k < n2; k++) {
                    tmp = dp[n1][k] + dp[k + 1][n2] + (temp[n1][0] * temp[k][1] * temp[n2][1]);
                    dp[n1][n2] = dp[n1][n2] < tmp ? dp[n1][n2] : tmp;
                }
            }
        }
    }
    return dp[0][2];
}

int main(void) {
	int sol1, sol2;
	printf("Matrix Input: ");
	scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    srand((unsigned int)time(NULL));
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++)
            matrix1[i][j] = rand() % 9 + 1;
    }
    for (int i = 0; i < num2; i++) {
        for (int j = 0; j < num3; j++)
            matrix2[i][j] = rand() % 9 + 1;
    }
    for (int i = 0; i < num3; i++) {
        for (int j = 0; j < num4; j++)
            matrix3[i][j] = rand() % 9 + 1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 7; k++)
                tmp[i][j] += matrix2[i][k] * matrix3[k][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 3; k++)
                result[i][j] += matrix1[i][k] * tmp[k][j];
        }
    }
    printf("\noutput matrix: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++)
            printf("%5d ", result[i][j]);
        printf("\n");
    }

    temp[0][0] = num1;
    temp[0][1] = num2;
    temp[1][0] = num2;
    temp[1][1] = num3;
    temp[2][0] = num3;
    temp[2][1] = num4;

    sol1 = num1 * num2 * num3 + num1 * num3 * num4;
    sol2 = num2 * num3 * num4 + num1 * num2 * num4;
    printf("\nsolution1 >> (matrix1*matrix2)*matrix3: %d\n", sol1);
    printf("solution2 >> matrix1*(matrix2*matrix3): %d\n", sol2);
    printf("optimal chain order: solution2(%d)\n", sol1 < sol2 ? sol1 : sol2);

    int computation = solution(4);
    printf("\nthe minimum number of computations : %d\n", computation);


	return 0;
}
