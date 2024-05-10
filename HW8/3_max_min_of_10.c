/**
 * @file 3_max_min_of_10.c
 * @author Volkov Egor
 * @brief Сумма максимумов и минимумов
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

void find_min(int *a, size_t s){
    int min = a[0];
    size_t indx = 0;
    for(size_t i = 1; i < s; i++){
        if( a[i] < min ){
            min = a[i];
            indx = i;
        }
    }
    printf("%lu %d\n", indx + 1, min);
}

void find_max(int *a, size_t s){
    int max = a[0];
    size_t indx = 0;
    for(size_t i = 1; i < s; i++){
        if( a[i] > max ){
            max = a[i];
            indx = i;
        }
    }
    printf("%lu %d ", indx + 1, max);
}

#define SIZE 10

int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    find_max(a, SIZE);
    find_min(a, SIZE);
    return 0;
}