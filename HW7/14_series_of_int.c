/**
 * @file 14_series_of_int.c
 * @author Volkov Egor
 * @brief Нечетные числа последовательности интов
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

void print_only_even(){
    int n;
    scanf("%d", &n);
    if ( n == 0 ){
        printf("\n");
        return;
    }
    if ( n % 2 != 0 ){
        printf("%d ", n);
        print_only_even();
    } else {
        print_only_even();
    }
}

int main( void ){
    print_only_even();
    return 0;
}