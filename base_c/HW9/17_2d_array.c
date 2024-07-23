/**
 * @file 17_2d_array.c
 * @author Volkov Egor
 * @brief Двумерные массивы - зло. Линейная индексация в помощь!
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#define W 5
#define H 5

void get_2d_array(int* a){
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &a[i * W + j]);
        }
    }
}

void sum_of_main_diag(int* a, size_t w){
    int sum = 0;
    for(int i = 0; i < w; i++){
        sum += a[i * w + i];
    }
    printf("%d\n", sum);
}


int main() {
    int a[H * W] = {0};
    get_2d_array(a);
    sum_of_main_diag(a, W);
    return 0;
}
