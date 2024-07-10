/**
 * @file 15_max_of_series.c
 * @author Volkov Egor
 * @brief Максимум в последовательности чисел
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 */


#include <stdio.h>

int find_max( int max ){
    int tmp;
    scanf("%d", &tmp);
    if( tmp == 0 ){
        return max;
    }
    if( max < tmp ){
        max = tmp;
        return find_max(max);
    } else {
        return find_max(max);
    }

}

int main( void ){
    int n;
    scanf("%d", &n);
    printf("%d\n", find_max(n));
    return 0;
}