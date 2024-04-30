/**
 * @file 1_mod.c
 * @author Volkov Egor
 * @brief Функция взятия модуля
 * @version 0.1
 * @date 2024-04-25
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>


int mod(int n);


int main( void ){
    int n;
    scanf("%d", &n);
    printf("%d\n", mod(n));
    return 0;
}

int mod(int n){
    if ( n > 0 ){
        return n;
    } else if ( n < 0){
        return -n;
    } else {
        return 0;
    }
}