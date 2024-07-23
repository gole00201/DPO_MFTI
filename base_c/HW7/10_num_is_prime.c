/**
 * @file 10_num_is_prime.c
 * @author Volkov Egor
 * @brief Проверка на простоту числа
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int is_prime(int n, int divisor) {
    if (n <= 1) {
        return 0;
    }
    if (divisor == 1) {
        return 1;
    }
    if (n % divisor == 0) {
        return 0;
    } else {
        return is_prime(n, divisor - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (is_prime(n, n - 1)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
