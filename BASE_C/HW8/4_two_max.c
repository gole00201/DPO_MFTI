/**
 * @file 4_two_max.c
 * @author Volkov Egor
 * @brief Сумма двух максимумов
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

void find_two_max(int *a, size_t s){
    int max = a[0];
    size_t indx = 0;
    for(size_t i = 1; i < s; i++){
        if( a[i] > max ){
            max = a[i];
            indx = i;
        }
    }
    int max_2;
    if (max == a[0]){
        max_2 = a[1];
    } else {
        max_2 = a[0];
    }
    for(size_t i = 1; i < s; i++){
        if( (a[i] > max_2) && (i != indx)){
            max_2 = a[i];
        }
    }
    printf("%d\n", max + max_2);
}

#define SIZE 10

int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    find_two_max(a, SIZE);
    return 0;
}