/**
 * @file 12_sort_two_parts.c
 * @author Volkov Egor
 * @brief Сориторовка две части по разному
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

void put_array(int* a, size_t s){
    for(size_t i = 0; i < s; i++){
        printf("%d ", *(a + i));
    }
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int cmpr_max(int a, int b){
    return a - b;
}

int cmpr_min(int a, int b){
    return b - a;
}

void sort_by_cmpr(int *a, size_t s, int(*cmpr)(int, int)){
    for(size_t i = 0; i < s; i++){
        for(size_t j = 0; j < s - i - 1; j++){
            if(cmpr(a[j], a[j + 1]) > 0){
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

#define SIZE 10

int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    sort_by_cmpr(a, SIZE / 2, cmpr_max);
    sort_by_cmpr(a + SIZE / 2, SIZE / 2, cmpr_min);
    put_array(a, SIZE);
    printf("\n");
    return 0;
}