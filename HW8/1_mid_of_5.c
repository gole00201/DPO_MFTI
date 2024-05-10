/**
 * @file 1_mid_of_5.c
 * @author Volkov Egor
 * @brief Среднее арефметическое 5 чисел с массиовом
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
    printf("%.3f\n", tmp / (float)s);
}


int main( void ){
    int a[5] = {0};
    get_array(a, 5);
    calc_middle(a, 5);
    return 0;
}