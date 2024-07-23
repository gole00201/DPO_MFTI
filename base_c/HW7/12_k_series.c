/**
 * @file 12_k_series.c
 * @author Volkov Egor
 * @brief Выведите первые n членов этой последовательности
 * 1, 2, 2, 3, 3, 3, 4, 4, 4, 4
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void series( int n ){
    int count = 0;
    int k = 1;
    for (int i = 0; i < n; i++) {
        if (count < k) {
            printf("%d ", k);
            count++;
        } else {
            k++;
            count = 0;
            printf("%d ", k);
            count++;
        }
    }
}

int main( void ){
    int n;
    scanf("%d", &n);
    series(n);
    return 0;
}