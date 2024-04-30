/**
 * @file 12_sin.c
 * @author Volkov Egor
 * @brief Синус
 * @version 0.1
 * @date 2024-05-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <math.h> /* Только для точности*/
#define PI 3.14159


/* (╥﹏╥) ЭТО ПРИБЛИЖЕННОЕ ВЫЧИСЛЕНИЕ (╥﹏╥) */

float sinus(float x) {
    float radians = x * PI / 180.0;
    float result = 0.0;
    float term = radians;
    int n = 0;
    while (fabs(term) >= 0.001) {
        result += term;
        int exponent = 2 * n + 1;
        term = -term * radians * radians / ((exponent + 1) * (exponent + 2));
        n++;
    }
    return result;
}

int main() {
    float x;
    scanf("%f", &x);
    float result = sinus(x);
    return 0;
}
