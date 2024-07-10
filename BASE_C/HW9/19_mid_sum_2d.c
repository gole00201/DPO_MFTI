/**
 * @file 19_mid_sum_2d.c
 * @author Volkov Egor
 * @brief Больше линейной индексации!!!! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#define W 5
#define H 5

void get_2d_array(int* a, int w, int h){
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &a[i * w + j]);
        }
    }
}

float get_mid_sum_2d(int* a, int w, int h){
    int sum = 0;
    for(int i = 0; i < w; i++){
        sum += a[i * w + i];
    }
    return sum / 5.;
}

int cnt_bigger(int* a, int s, float val){
    int cnt = 0;
    for(int i = 0; i < s; i ++){
        if( a[i] > val ){
            cnt++;
        }
    }
    return cnt;
}


int main( void ){
    int a[W * H] = {0};
    get_2d_array(a, W, H);
    float sum = get_mid_sum_2d(a, W, H);
    int res = cnt_bigger(a, W * H, sum);
    printf("%d\n", res);
}