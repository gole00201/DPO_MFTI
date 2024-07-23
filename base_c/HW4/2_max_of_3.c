/**
 * @file 1_max_of_3.c
 * @author Volkov Egor
 * @brief Вывод большего числа из трех
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main( void ){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int max = a;
    if (max < b){
        max = b;
    }
    if (max < c){
        max = c;
    }
    printf("%d\n", max);
    return 0;
}