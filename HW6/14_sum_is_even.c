/**
 * @file 14_sum_is_even.c
 * @author Volkov Egor
 * @brief Сумма цифр четная
 * @version 0.1
 * @date 2024-05-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

void is_digit_sum_even(int num){
    int sum = 0;
    while(num > 0){
        int tmp = num % 10;
        sum += tmp;
        num /= 10;
    }
    if ( sum % 2 == 0 ){
        printf("YES");
    } else {
        printf("NO");
    }

}

int main( void ){
    int num;
    scanf("%d", &num);
    is_digit_sum_even(num);
    return 0;
}