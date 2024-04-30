/**
 * @file 2_pow.c
 * @author Volkov Egor
 * @brief Возведение в степень
 * @version 0.1
 * @date 2024-04-25
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int power(int n, int p){
    int ret_val = n;
    if ( p == 0 ){
        return 1;
    }
    for( int i = 1; i < p; i++ ){
        ret_val *= n;
    }
    return ret_val;
}

int main( void ){
    int n, p;
    scanf("%d %d", &n, &p);
    printf("%d\n", power(n, p));
    return 0;
}