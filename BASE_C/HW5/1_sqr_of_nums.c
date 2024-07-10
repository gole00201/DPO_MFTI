/**
 * @file 1_sqr_of_nums.c
 * @author Volkov Egor
 * @brief Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа. Число не превосходит 100.
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n > 100) {
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        int square = i * i;
        int cube = i * i * i;
        printf("%d %d %d\n", i, square, cube);
    }
    return 0;
}
