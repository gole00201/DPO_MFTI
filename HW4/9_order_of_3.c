/**
 * @file 9_order_of_3.c
 * @author Volkov Egor
 * @brief Порядок возрастения чисел
 * @version 0.1
 * @date 2024-04-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a < b && b < c) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
