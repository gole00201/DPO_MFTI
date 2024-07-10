/**
 * @file 2_min_of_5.c
 * @author Volkov Egor
 * @brief Максимальный элемент массива
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
    for(size_t i = 1; i < s; i++){
        if( a[i] < min ){
            min = a[i];
        }
    }
    printf("%d\n", min);
}


int main( void ){
    int a[5] = {0};
    get_array(a, 5);
    find_min(a, 5);
    return 0;
}