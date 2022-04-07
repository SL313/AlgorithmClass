#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int A[30][10], B[10][50], C[30][50] = { 0 }; // 처음 Matrix
int a1[15][5], a2[15][5], a3[15][5], a4[15][5]; // Matrix A를 쪼개서 a1, a2, a3, a4로 만든다.
int b1[5][25], b2[5][25], b3[5][25], b4[5][25]; // Matrix B를 쪼개서 b1, b2, b3, b4로 만든다.
int tmp1[15][5], tmp2[5][25]; // 임시 저장공간
int M1[15][25], M2[15][25], M3[15][25], M4[15][25], M5[15][25], M6[15][25], M7[15][25]; // Strassen 규칙에 사용
int c1[15][25], c2[15][25], c3[15][25], c4[15][25]; // Matrix C가 쪼개진 상태
int start1, end1, start2, end2;
float res1, res2;

void makeMatrix() {
    int check = 1;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 10; j++)
            A[i][j] = check;
        check++;
    } // 30*10 matrix
    check = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++)
            B[i][j] = check;
        check++;
    } // 10*50 matrix
}

void makeMatrixC() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 10; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

void print() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 50; j++)
            printf("%4d ", C[i][j]);
        printf("\n");
    }
    printf("\n");
}

void divideMatrix() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 10; j++) {
            if (i < 15 && j < 5) a1[i][j] = A[i][j];
            else if (i < 15 && j >= 5) a2[i][j - 5] = A[i][j];
            else if (i >= 15 && j < 5) a3[i - 15][j] = A[i][j];
            else a4[i - 15][j - 5] = A[i][j];
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            if (i < 5 && j < 25) b1[i][j] = B[i][j];
            else if (i < 5 && j >= 25) b2[i][j - 25] = B[i][j];
            else if (i >= 5 && j < 25) b3[i - 5][j] = B[i][j];
            else b4[i - 5][j - 25] = B[i][j];
        }
    }

}

//int multiplication(int *arr1[15][5], int *arr2[5][25]) {
//    for (int i = 0; i < 15; i++) {
//        for (int j = 0; j < 25; j++) {
//            for(int k=0; k<5; k++)
//
//        }
//    }
//}

void makeM1() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++)
            tmp1[i][j] = a1[i][j] + a4[i][j];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 25; j++)
            tmp2[i][j] = b1[i][j] + b4[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M1[i][j] += tmp1[i][k] * tmp2[k][j];
        }
    }
}

void makeM2() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++)
            tmp1[i][j] = a3[i][j] + a4[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M2[i][j] += tmp1[i][k] * b1[k][j];
        }
    }
}

void makeM3() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 25; j++)
            tmp2[i][j] = b2[i][j] - b4[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M3[i][j] += a1[i][k] * tmp2[k][j];
        }
    }
}

void makeM4() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 25; j++)
            tmp2[i][j] = b3[i][j] - b1[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M4[i][j] += a4[i][k] * tmp2[k][j];
        }
    }
}

void makeM5() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++)
            tmp1[i][j] = a1[i][j] + a2[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M5[i][j] += tmp1[i][k] * b4[k][j];
        }
    }
}

void makeM6() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++)
            tmp1[i][j] = a3[i][j] - a1[i][j];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 25; j++)
            tmp2[i][j] = b1[i][j] + b2[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M6[i][j] += tmp1[i][k] * tmp2[k][j];
        }
    }
}

void makeM7() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++)
            tmp1[i][j] = a2[i][j] - a4[i][j];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 25; j++)
            tmp2[i][j] = b3[i][j] + b4[i][j];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 5; k++)
                M7[i][j] += tmp1[i][k] * tmp2[k][j];
        }
    }
}

void makeSmallC() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 25; j++) {
            c1[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            c2[i][j] = M3[i][j] + M5[i][j];
            c3[i][j] = M2[i][j] + M4[i][j];
            c4[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
}

void makeBigC() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 50; j++) {
            if (i < 15 && j < 25) C[i][j] = c1[i][j];
            else if (i < 15 && j >= 25) C[i][j] = c2[i][j - 25];
            else if (i >= 15 && j < 25) C[i][j] = c3[i - 15][j];
            else C[i][j] = c4[i - 15][j - 25];
        }
    }
}

int main(void) {
    makeMatrix();
    start1 = clock();
    makeMatrixC();
    printf("ordinary multiplication: \n");
    print();
    end1 = clock();
    res1 = (float)(end1 - start1) / CLOCKS_PER_SEC;
    start2 = clock();
    divideMatrix();
    makeM1();
    makeM2();
    makeM3();
    makeM4();
    makeM5();
    makeM6();
    makeM7();
    makeSmallC();
    makeBigC();
    printf("Strassen multplication: \n");
    print();
    end2 = clock();
    res2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
    printf("ordinary multiplication: %.3f \n", res1);
    printf("Strassen multiplication: %.3f \n", res2);
	return 0;
}
