/**
 * @file 16_find_aften.c
 * @author Volkov Egor
 * @brief Элемент только один
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void get_array(int* a, size_t s) {
    for (size_t i = 0; i < s; i++) {
        scanf("%d", (a + i));
    }
}

void print_often(int* a, size_t s){
    for(size_t i = 0; i < s; i++){
        int cnt_tmp = 0;
        for(size_t j = 0; j < s; j++){
            if( i == j ){
                continue;
            } else {
                if( a[i] == a[j] ){
                    cnt_tmp++;
                }
            }
        }
        if( cnt_tmp == 0 ){
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}



int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    print_often(a, SIZE);
    return 0;
}

