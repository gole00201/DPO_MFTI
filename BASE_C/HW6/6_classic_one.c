/**
 * @file 7_classic_one.c
 * @author Volkov Egor
 * @brief Классическая задачка
 * @version 0.1
 * @date 2024-04-25
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

double power(int n, int p){
    double ret_val = n;
    if ( p == 0 ){
        return 1;
    }
    for( int i = 1; i < p; i++ ){
        ret_val *= n;
    }
    return ret_val;
}

int main( void ){
    int n;
    scanf("%d", &n);
    printf("%.0f\n", power(2, n - 1));
    return 0;
}