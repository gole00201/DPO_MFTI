/**
 * @file 11_nod.c
 * @author Volkov Egor
 * @brief Алгоритм Евклида
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int nod(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    int result = nod(a, b);
    printf("%d\n", result);
    return 0;
}
