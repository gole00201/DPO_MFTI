/**
 * @file 11_triangle.c
 * @author Volkov Egor
 * @brief Проверка условий существования теруголтника
 * @version 0.1
 * @date 2024-04-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
