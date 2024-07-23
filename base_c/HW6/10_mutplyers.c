/**
 * @file 10_mutplyers.c
 * @author Volkov Egor
 * @brief Множители числа
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void print_simple(int n){
    int tmp = n;
    int i = 2;
    while( i < n ){
        if (tmp % i == 0){
            printf("%d ", i);
            tmp /= i;
            i = 2;
        } else {
            i++;
        }
    }
    if( tmp == n ){
        printf("%d", n);
    }


}

int main( void ){
    int n;
    scanf("%d", &n);
    print_simple(n);
    return 0;
}