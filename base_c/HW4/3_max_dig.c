/**
 * @file 3_max_dig.c
 * @author Volkov Egor (gole00201@gmail.com)
 * @brief Макисмальная цифра числа
 * @version 0.1
 * @date 2024-04-14
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int main( void ){

    int num;
    int max = -1;
    scanf("%d", &num);

    while(num > 0){
        int tmp = num % 10;
        if(tmp > max){
            max = tmp;
        }
        num /= 10;
    }

    printf("%d\n", max);
    return 0;
}