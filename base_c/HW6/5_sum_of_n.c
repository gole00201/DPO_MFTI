/**
 * @file 5_sum_of_n.c
 * @author Volkov Egor
 * @brief Сумма 1..n
 * @version 0.1
 * @date 2024-04-25
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>


int from_1_to_n( int N ){
    int ret_val = 0;
    for (size_t i = 1; i <= N; i++)
    {
        ret_val += i;
    }
    return ret_val;
}

int main( void ){
    int N;
    scanf("%d", &N);
    printf("%d\n", from_1_to_n(N));
    return 0;
}