/**
 * @file 13_find_2d_not_0.c
 * @author Volkov Egor
 * @brief Отобрать числа, у которых 10 == ноль
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <stdlib.h>

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

size_t cnt_if_10_is_0(int *a, size_t s){
    size_t cnt = 0;
    for(size_t i = 0; i < s; i++){
        if(((a[i] / 10) % 10) == 0){
            cnt++;
        }
    }
    return cnt;
}

void put_if_10_is_0(int *a, int *b, size_t s){
    size_t inner_i = 0;
    for(size_t i = 0; i < s; i++){
        if(((a[i] / 10) % 10) == 0){
            b[inner_i] = a[i];
            inner_i++;
        }
    }
}

#define SIZE 10


int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    size_t cnt = cnt_if_10_is_0(a, SIZE);
    int *b = (int *)malloc(cnt * sizeof(int));
    put_if_10_is_0(a, b, SIZE);
    put_array(b, cnt);
    free(b);
    return 0;
}