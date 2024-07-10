/**
 * @file 16_black_and_white.c
 * @author Volkov Egor
 * @brief Шахматы
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int main(void) {
    char column;
    int row;
    scanf("%c %d", &column, &row);
    int column_index = column - 'A' + 1;
    if((column_index + row) % 2 == 0){
        printf("BLACK\n");
    } else {
        printf("WHITE\n");
    }
    return 0;
}
