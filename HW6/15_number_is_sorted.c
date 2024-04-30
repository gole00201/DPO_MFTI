/**
 * @file 15_number_is_sorted.c
 * @author Volkov Egor
 * @brief Цифры в поряде
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void number_is_sorted( int num ){
    int prev = 99999;
    while(num > 0){
        int tmp = num % 10;
        if( prev <= tmp ){
            printf("NO");
            return;
        }
        prev = tmp;
        num /= 10;
    }
    printf("YES");
}

int main( void ){
    int num;
    scanf("%d", &num);
    number_is_sorted(num);
    return 0;
}