/**
 * @file 2_for_num_to_num_sq.c
 * @author Volkov Egor
 * @brief Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b
 * @version 0.1
 * @date 2024-04-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int main ( void ){
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b){
        return 1;
    }
    for(int i = a; i <= b; ++i){
        printf("%d ", i * i);
    }
    printf("\n");
    return 0;
}