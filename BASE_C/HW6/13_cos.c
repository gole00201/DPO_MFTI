/**
 * @file 13_cos.c
 * @author Volkov Egor
 * @brief Косинус
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <math.h>
#define PI 3.14159

/* (╥﹏╥) ЭТО ПРИБЛИЖЕННОЕ ВЫЧИСЛЕНИЕ (╥﹏╥) */

float cosinus(float x) {
    float radians = x * PI / 180.0;
    float result = 0.0;
    float term = 1.0;

    int n = 0;
    while (fabs(term) >= 0.001) {
        result += term;
        int exponent = 2 * n;
        term = -term * radians * radians / ((2 * n + 1) * (2 * n + 2));
        n++;
    }

    return result;
}

int main() {
    float x;
    scanf("%f", &x);
    float result = cosinus(x);
    printf("%.3f\n", result);
    return 0;
}
