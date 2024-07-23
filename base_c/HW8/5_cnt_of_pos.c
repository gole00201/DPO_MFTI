/**
 * @file 5_cnt_of_pos.c
 * @author Volkov Egor
 * @brief Сумма положительных
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <stdint.h>

void get_array(int* a, size_t s){
    for(size_t i = 0; i < s; i++){
        scanf("%d", (a + i));
    }
}

void cnt_pos(int* a, size_t s){
    int sum = 0;
    for(size_t i = 0; i < s; i++){
        if( a[i] > 0){
            sum += a[i];
        }
    }
    printf("%d\n", sum);
}

#define SIZE 10

int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    cnt_pos(a, SIZE);
    return 0;
}