/**
 * @file 8_rev_two_parts.c
 * @author Volkov Egor
 * @brief Развернуть три части массива
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

void flip_array(int* a, size_t s){
    for(size_t i = 0; i < s / 2; i++){
        int tmp = a[i];
        a[i] = a[s - i - 1];
        a[s - i - 1] = tmp;
    }
}

#define SIZE 12
#define PARTS 3

int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    flip_array(a, SIZE / PARTS);
    flip_array(a + SIZE / PARTS, SIZE / PARTS);
    flip_array(a + SIZE / PARTS + SIZE / PARTS, SIZE / PARTS);
    put_array(a, SIZE);
    printf("\n");
    return 0;
}


