/**
 * @file 6_mid_of_12.c
 * @author Volkov Egor
 * @brief СА 12 элементов
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void get_array(int* a, size_t s){
    for(size_t i = 0; i < s; i++){
        scanf("%d", (a + i));
    }
}

void calc_middle(int *a, size_t s){
    int tmp = 0;
    for(size_t i = 0; i < s; i++){
        tmp += a[i];
    }
    printf("%.2f\n", tmp / (float)s);
}

#define SIZE 12

int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    calc_middle(a, SIZE);
    return 0;
}