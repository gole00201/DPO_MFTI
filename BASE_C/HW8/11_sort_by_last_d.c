/**
 * @file 11_sort_by_last_d.c
 * @author Volkov Egor
 * @brief Сортировка по последней цифре
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

int last_d(int n){
    return n % 10;
}

int cmpr_by_last_d(int a, int b){
    return last_d(a) - last_d(b);
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
    sort_by_cmpr(a, SIZE, cmpr_by_last_d);
    put_array(a, SIZE);
    printf("\n");
    return 0;
}