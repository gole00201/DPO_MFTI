/**
 * @file 5_sum_of_dig.c
 * @author Volkov Egor (gole00201@gmail.com)
 * @brief Сумма цифр числа
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main( void ){

    int num;
    int sum = 0;
    scanf("%d", &num);
    if (num < 0){
        return 1;
    }

    while(num > 0){
        int tmp = num % 10;
        sum += tmp;
        num /= 10;
    }

    printf("%d\n", sum);
    return 0;
}