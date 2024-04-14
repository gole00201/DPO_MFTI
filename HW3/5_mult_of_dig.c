/**
 * @file 5_mult_of_dig.c
 * @author Volkov Egor (gole00201@gmail.com)
 * @brief Произведение цифр числа
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main( void ){

    int num;
    int mult = 1;
    scanf("%d", &num);

    while(num > 0){
        int tmp = num % 10;
        mult *= tmp;
        num /= 10;
    }

    printf("%d\n", mult);
    return 0;
}