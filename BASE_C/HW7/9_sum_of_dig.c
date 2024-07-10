/**
 * @file 9_sum_of_dig.c
 * @author Volkov Egor
 * @brief Сумма цифр рекурсивно
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int sum_of_dig(int n){
    if (n < 10) {
        return n;
    } else {
        return (n % 10) + sum_of_dig(n / 10);
    }
}


int main( void ){
    int n;
    scanf("%d", &n);
    printf("%d", sum_of_dig(n));
    return 0;
}