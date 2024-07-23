/**
 * @file 13_mulriplyers_r.c
 * @author Volkov Egor
 * @brief Простые множители числа рекеурсивно
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void print_simple(int n, int dev){
    if( n == 1 ){
        return;
    }
    if( dev == n){
        printf("%d", n);
        return;
    }
    if( n % dev == 0 ){
        printf("%d ", dev);
        print_simple(n / dev, 2);
    } else {
        print_simple(n, ++dev);
    }
}


int main( void ){
    int n;
    scanf("%d", &n);
    print_simple(n, 2);
    return 0;
}