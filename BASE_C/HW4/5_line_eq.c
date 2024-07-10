/**
 * @file 5_line_eq.c
 * @author Volkov Egor
 * @brief Уравнение прямой по координатам двух точек
 * @version 0.1
 * @date 2024-04-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int main( void ){
    float x1, x2, y1, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    float k = (y2 - y1) / (x2 - x1);
    float b = y1 - k * x1;
    printf("%.2f %.2f\n", k, b);
    return 0;
}