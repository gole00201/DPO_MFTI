/**
 * @file 3_mid_of_twof.c
 * @author Volkov Egor
 * @brief Функиц япоиска среднего арефметического
 * @version 0.1
 * @date 2024-04-25
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int middle( int a, int b ){
    return ((a + b) / 2);
}

int main( void ){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", middle(a, b));
    return 0;
}