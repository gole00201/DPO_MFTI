/**
 * @file 4_find_common.c
 * @author Volkov Egor
 * @brief Пришлось попотеть
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#define MAX_LENGTH 100


bool is_unique_in_both(const char *str1, const char *str2, char ch) {
    int count1 = 0, count2 = 0;
    while (*str1 != '\0') {
        if (*str1 == ch)
            count1++;
        str1++;
    }
    while (*str2 != '\0') {
        if (*str2 == ch)
            count2++;
        str2++;
    }
    return count1 == 1 && count2 == 1;
}

void fprintf_unique_chars(FILE *output, const char *str1, const char *str2) {
    char result[MAX_LENGTH] = {0};
    int result_idx = 0;
    bool first = true;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (is_unique_in_both(str1, str2, ch)) {
            if (!first) {
                result[result_idx++] = ' ';
            } else {
                first = false;
            }
            result[result_idx++] = ch;
        }
    }
    fprintf(output, "%s\n", result);
}


int main( void ){
    char str1[MAX_LENGTH] = {0};
    char str2[MAX_LENGTH] = {0};
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Ошибка открытия файлов: %s\n", strerror(errno));
        return 1;
    }
    if (fscanf(input_file, "%s %s", str1, str2) != 2) {
        fprintf(stderr, "Ошибка чтения слов\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }
    fprintf_unique_chars(output_file, str1, str2);
    return 0;
}