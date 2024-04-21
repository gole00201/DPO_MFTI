/**
 * @file 1_order_of_2.c
 * @author Два числа в порядке возрастания
 * @brief
 * @version 0.1
 * @date 2024-04-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int min_num = (a < b) ? a : b;
    int max_num = (a > b) ? a : b;
    printf("%d %d\n", min_num, max_num);
    return 0;
}
