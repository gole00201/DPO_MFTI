/**
 * @file 2_mult_and_sum_of_3.c
 * @author Volkov Egor (gole00201@gmail.com)
 * @brief Сумма и произведение трех чисел
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main( void ){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d+%d+%d=%d\n", a, b, c, a + b + c);
    printf("%d*%d*%d=%d\n", a, b, c, a * b * c);
    return 0;
}