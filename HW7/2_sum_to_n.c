/**
 * @file 2_sum_to_n.c
 * @author Volkov Egor
 * @brief Рекурсивная сумма от 1 до N
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */


#include <stdio.h>

void print_n_sum(int n, int val, int sum){
    if (val <= n){
        sum += val;
        print_n_sum(n, ++val, sum);
    } else {
        printf("%d", sum);
    }
}

int main( void ){
    int n;
    scanf("%d", &n);
    print_n_sum(n, 1, 0);
    return 0;
}