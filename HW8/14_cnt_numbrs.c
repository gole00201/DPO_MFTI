/**
 * @file 14_cnt_numbrs.c
 * @author Volkov Egor
 * @brief Выделить массив повторяющихся чисел
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#define SIZE 10

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

int is_in_array(int* a, size_t s, int val){
    for(size_t i = 0; i < s; i++){
        if( a[i] == val ){
            return 1;
        }
    }
    return 0;
}

void get_repeated(int *a, size_t s){
    int tmp[SIZE] = {0};
    for(size_t i = 0; i < s; i++){
        for(size_t j = 0; j < s; j++){
            if( i == j ){
                continue;
            } else {
                if( a[i] == a[j] ){
                    if( !is_in_array(tmp, SIZE, a[i]) ){
                        tmp[i] = a[i];
                        printf("%d ", a[i]);
                    }
                }
            }
        }
    }
    printf("\n");
}


int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    get_repeated(a, SIZE);
    return 0;
}