/**
 * @file 18_print_d_div_by.c
 * @author Volkov egor
 * @brief Счетчики чисел
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void get_div(int N){
    int a[8] = {0};
    for(int j = 2; j <= 9; j++){
        for(int i = 1; i <= N; i++){
            if( i % j == 0 ){
                a[j - 2]++;
            }
        }
    }
    for(int i = 0; i < 8; i++){
        printf("%d %d\n", i + 2, a[i]);
    }

}

int main( void ){
    int N;
    scanf("%d", &N);
    get_div(N);
    return 0;
}

