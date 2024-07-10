/**
 * @file 10_seasons.c
 * @author Volkov Egor
 * @brief Вывод времени года
 * @version 0.1
 * @date 2024-04-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int main() {
    int month;
    scanf("%d", &month);
    if (month == 12 || month == 1 || month == 2) {
        printf("winter\n");
    } else if (month >= 3 && month <= 5) {
        printf("spring\n");
    } else if (month >= 6 && month <= 8) {
        printf("summer\n");
    } else if (month >= 9 && month <= 11) {
        printf("autumn\n");
    }
    return 0;
}
