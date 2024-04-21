/**
 * @file 4_is_three_dig.c
 * @author Volkov Egor
 * @brief Здесь три цифры?
 * @version 0.1
 * @date 2024-04-21
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>

int main ( void ){
    int num;
    scanf("%d", &num);
    int i = 0;
    while (num > 0)
    {
        i++;
        num /= 10;
    }
    if (i == 3){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}