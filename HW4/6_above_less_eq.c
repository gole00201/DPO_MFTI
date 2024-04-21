/**
 * @file 6_above_less_eq.c
 * @author Volkov Egor
 * @brief Above Less Eq
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <stdio.h>

int main( void ){
    int a, b;
    scanf("%d %d", &a, &b);
    if(a > b){
        printf("Above\n");
    } else if (a < b) {
        printf("Less\n");
    } else{
        printf("Equal\n");
    }
    return 0;
}