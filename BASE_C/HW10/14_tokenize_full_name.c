/**
 * @file 13_tokenize_full_name.c
 * @author Volkov Egor
 * @brief
 * @version 0.1
 * @date 2024-05-22
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#define MAX_LENGTH 100

int main(void) {
    char str[MAX_LENGTH + 1] = {0};
    char first_name[MAX_LENGTH / 3] = {0};
    char last_name[MAX_LENGTH / 3] = {0};
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Ошибка открытия файлов: %s\n", strerror(errno));
        if (input_file != NULL) fclose(input_file);
        if (output_file != NULL) fclose(output_file);
        return 1;
    }
    fscanf(input_file, "%s%s", last_name, first_name);
    fprintf(output_file, "Hello, %s %s!", first_name, last_name);
    fclose(input_file);
    fclose(output_file);
    return 0;
}
