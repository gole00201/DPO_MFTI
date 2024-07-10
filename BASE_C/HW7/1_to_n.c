/**
 * @file 1_to_n.c
 * @author Volkov Egor
 * @brief Рекурсивная печать от 1 до N
 * @version 0.1
 * @date 2024-05-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

void print_n(int n, int val){
    if (val <= n){
        printf("%d ", val);
        print_n(n, ++val);
    }
}


int main( void ){
    int n;
    scanf("%d", &n);
    print_n(n, 1);
    return 0;
}