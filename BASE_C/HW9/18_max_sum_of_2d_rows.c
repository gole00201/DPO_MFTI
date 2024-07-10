/**
 * @file 18_max_sum_of_2d_rows.c
 * @author Volkov Egor
 * @brief Больше линейной индексации богу линейной индексации! ＼(￣▽￣)／
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#define W 10
#define H 10
#define GEEL(arr, i, j) (arr[(i) * (W) + (j)]) /* GET ELEMENT */

void get_2d_array(int* a, int w, int h){
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &a[i * w + j]);
        }
    }
}

int get_max_rows_sum_2d(int* a, int w, int h){
    int sum = 0;
    for(int i = 0; i < h; i++){
        int max = a[i * w + 0];
        for(int j = 0; j < w; j++){
            if (GEEL(a, i, j) > max){
                max = GEEL(a, i, j);
            }
        }
        sum += max;
    }
    return sum;
}

int main( void ){
    int a[W * H] = {0};
    get_2d_array(a, W, H);
    int sum = get_max_rows_sum_2d(a, W, H);
    printf("%d\n", sum);
}