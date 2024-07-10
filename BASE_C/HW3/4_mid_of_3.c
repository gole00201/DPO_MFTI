/**
 * @file 4_mid_of_3.c
 * @author Volkov Egor (gole00201@gmail.com)
 * @brief Среднее арф. трех чисел
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

const float n = 3;

int main ( void ){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%.2f\n", (a + b + c) / n);
    return 0;
}