/**
 * @file 9_circle_arr.c
 * @author Volkov Egor
 * @brief Циклический сдвиг массива
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


void mov_r(int* a, size_t s, int n){
    for(int i = 0; i < n; i++){
        int tmp = a[s - 1];
        for(size_t i = s - 1; i > 0; i--){
            a[i] = a[i - 1];
        }
        a[0] = tmp;
    }
}

#define SIZE 10

int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    mov_r(a, SIZE, 1);
    put_array(a, SIZE);
    printf("\n");
    return 0;
}

