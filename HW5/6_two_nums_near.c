/**
 * @file 6_two_nums_near.c
 * @author Volkov Egor
 * @brief Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.
 * @version 0.1
 * @date 2024-04-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int main( void ){

    int num;
    int sum = 0;
    scanf("%d", &num);
    int tmp = -1;
    while(num > 0){
        if(tmp  == num % 10){
            printf("YES\n");
            return 0;
        }
        tmp = num % 10;
        num /= 10;
    }
    printf("NO\n");
    return 0;
}