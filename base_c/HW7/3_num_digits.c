/**
 * @file 3_num_digits.c
 * @author Volkov Egor
 * @brief Цифры числа, рекурсивно и в обратном порядке
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void print_digits_r(int n) {
    if (n < 10) {
        printf("%d ", n);
    } else {
        printf("%d ", n % 10);
        print_digits_r(n / 10);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    print_digits_r(n);
    return 0;
}
