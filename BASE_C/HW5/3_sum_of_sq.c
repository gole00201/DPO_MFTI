/**
 * @file 3_sum_of_sq.c
 * @author Volkov Egor
 * @brief Сумма квадратов
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int sum = 0;
    if (a > b){
        return 1;
    }
    for (int i = a; i <= b; i++) {
        sum += i * i;
    }
    printf("%d\n", sum);
    return 0;
}
