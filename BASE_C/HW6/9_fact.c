/**
 * @file 9_fact.c
 * @author Volkov Egor
 * @brief Факториал числа
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 */


#include <stdio.h>

int factorial( int n ){
    int ret_val = 1;
    for(int i = 1; i <= n; i++){
        ret_val *= i;
    }
    return ret_val;
}

int main( void ){
    int n;
    scanf("%d", &n);
    n = factorial(n);
    printf("%d", n);
    return 0;
}