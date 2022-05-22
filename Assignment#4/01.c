#include <stdio.h>

int result[100] = { 0 };

int fibo(int num) {
    if (num < 2)
        return num;
    else {
        if (result[num] == 0)
            result[num] = fibo(num - 1) + fibo(num - 2);
        return result[num];
    }
}

int main(void) {
    printf("The result of\n");
    printf(" Fibonacci(5): %d\n", fibo(5));
    printf(" Fibonacci(10): %d\n", fibo(10));
    return 0;
}
