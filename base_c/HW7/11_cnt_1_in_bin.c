/**
 * @file 11_cnt_1_in_bin.c
 * @author Volkov Egor
 * @brief Подсчет 1
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void dec_to_bin(int num, int cnt){
    if( num < 2 ){
        if( num % 2 == 1 ){
            cnt += 1;
        }
        printf("%d", cnt);
    } else {
        if( num % 2 == 1 ){
            cnt += 1;
        }
        dec_to_bin(num / 2, cnt);
    }
}

int main( void ){
    int n;
    scanf("%d", &n);
    dec_to_bin(n, 0);
    return 0;
}