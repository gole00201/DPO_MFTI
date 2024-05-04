/**
 * @file 5_dec_to_bin.c
 * @author Volkov Egor
 * @brief Перевести натуральное число в двоичную систему счисления
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>

void dec_to_bin(int num){
    if( num < 2 ){
        printf("%d", num % 2);
    } else {
        dec_to_bin(num / 2);
        printf("%d", num % 2);
    }
}

int main( void ){
    int n;
    scanf("%d", &n);
    dec_to_bin(n);
    return 0;
}