/**
 * @file 8_a_to_b.c
 * @author Volkov Egor
 * @brief Печать от А до Б
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>

void print_a_to_b(int a, int b){
    if (a == b ){
        printf("%d ", a);
    } else if ( a < b ){
        printf("%d ", a);
        print_a_to_b(a + 1, b);
    } else {
        printf("%d ", a);
        print_a_to_b(a - 1, b);
    }
}


int main( void ){
    int a, b;
    scanf("%d %d", &a, &b);
    print_a_to_b(a, b);
    return 0;
}