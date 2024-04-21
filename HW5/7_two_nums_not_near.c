/**
 * @file 7_two_nums_not_near.c
 * @author Volkov Egor
 * @brief Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, НЕ ОБЯЗАТЕЛЬНО рядом.
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);
    int cnt[10] = {0};
    while (number > 0) {
        int digit = number % 10;
        cnt[digit]++;
        number /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] >= 2) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
