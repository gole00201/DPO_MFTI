/**
 * @file 8_lowwer_to_upper.c
 * @author Volkov Egor
 * @brief Смена нижнего регистра на вверхний
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - (' ');
    } else {
        return c;
    }
}

int main(void) {
    char c;
    while ((c = getchar()) != '.') {
        printf("%c", toUpper(c));
    }
    printf("\n");
    return 0;
}
