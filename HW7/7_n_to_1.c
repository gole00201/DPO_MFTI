/**
 * @file 7_n_to_1.c
 * @author Volkov Egor
 * @brief Печать от N до 1 рекурсивно
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void print_n(int n, int val){
    if (val < n){
        print_n(n, ++val);
        printf("%d ", val);
    }
}


int main( void ){
    int n;
    scanf("%d", &n);
    print_n(n, 0);
    return 0;
}