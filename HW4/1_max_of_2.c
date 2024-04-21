/**
 * @file 1_max_of_2.c
 * @author Volkov Egor
 * @brief Вывод большего числа из двух
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main( void ){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a > b ? a : b);
    return 0;
}