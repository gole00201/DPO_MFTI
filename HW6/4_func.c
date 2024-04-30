/**
 * @file 4_func.c
 * @author Volkov Egor
 * @brief Вычисление функции и однопроходная реализация
 * @version 0.1
 * @date 2024-04-25
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>


int f(int x){
    if ( -2 <= x && x < 2 ){
        return x * x;
    } else if ( x >= 2 ){
        return x * x + 4 * x + 5;
    } else {
        return 4;
    }
}


int main( void ){
    int max = -2147483648; /* Можно макросом MIN_INT, но мы же не ищем легких путей.*/
    while(1){
        int tmp;
        scanf("%d", &tmp);
        if ( tmp == 0 ) break;
        tmp = f(tmp);
        if( tmp > max ){
            max = tmp;
        }
    }
    printf("%d\n", max);
    return 0;
}