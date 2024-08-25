#include <stdio.h>

/* Для заданных натуральных чисел N и K требуется вычислить количество чисел от 1 до N,
имеющих в двоичной записи ровно K нулей. Например, если N=8 и K=1, то мы можем записать
все числа от 1 до 8 в двоичной системе счисления: 1, 10, 11, 100, 101, 110, 111 и 1000.
Откуда видно, что только числа 10, 101 и 110
имеют ровно один ноль в записи, т.е. правильный ответ – 3. */

int count_zeros_in_binary(int num) {
    int count = 0;
    while (num > 0) {
        if ((num & 1) == 0) {
            count++;
        }
        num >>= 1;
    }
    return count;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (count_zeros_in_binary(i) == K) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
