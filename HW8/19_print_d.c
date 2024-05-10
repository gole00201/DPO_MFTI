/**
 * @file 19_print_d.c
 * @author Volkov Egor
 * @brief Числа в прямом порядке
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void print_digits_r(int n) {
    if (n < 10) {
        printf("%d ", n);
    } else {
        print_digits_r(n / 10);
        printf("%d ", n % 10);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    print_digits_r(n);
    printf("\n");
    return 0;
}
