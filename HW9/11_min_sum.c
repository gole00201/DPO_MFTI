/**
 * @file 11_min_sum.c
 * @author Volkov Egor
 * @brief Минимальная суммая
 * @version 0.1
 * @date 2024-05-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#define SIZE 30

void get_array(int* a, size_t s){
    for(size_t i = 0; i < s; i++){
        scanf("%d", (a + i));
    }
}

void printf_min_sum(int* a, size_t s){
    int min = a[0] + a[1];
    int it_1 = 0;
    int it_2 = 1;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            if( j == i ){
                continue;
            }
            if( a[j] + a[i] < min){
                min = a[j] + a[i];
                it_1 = j;
                it_2 = i;
            }
        }
    }
    if( it_1 > it_2 ){
        printf("%d %d", it_2, it_1);
    } else {
        printf("%d %d", it_1, it_2);
    }
}



int main( void ){
    int a[SIZE] = { 0 };
    get_array(a, SIZE);
    printf_min_sum(a, SIZE);
    return 0;
}