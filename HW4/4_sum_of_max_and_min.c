/**
 * @file 4_sum_of_max_and_min.c
 * @author Volkov Egor
 * @brief Поиск суммы максимума и минимума
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int max2(int max, int b){
    return max < b ? b : max;
}

int min2(int min, int b){
    return min > b ? b : min;
}

int main( void ){
    int a, b, c, d, g;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &g);
    int max = a;
    int min = a;
    max = max2(max, a);
    max = max2(max, b);
    max = max2(max, c);
    max = max2(max, d);
    max = max2(max, g);
    min = min2(min, a);
    min = min2(min, b);
    min = min2(min, c);
    min = min2(min, d);
    min = min2(min, g);
    printf("%d\n", max + min);
    return 0;
}