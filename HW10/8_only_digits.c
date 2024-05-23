#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

void extract_and_sort_numbers(const char *str, int *numbers, int *num_count) {
    int len = strlen(str);
    int num = 0;
    bool in_number = false;

    *num_count = 0;
    for (int i = 0; i <= len; i++) {
        if (is_digit(str[i])) {
            num = num * 10 + (str[i] - '0');
            in_number = true;
        } else {
            if (in_number) {
                numbers[(*num_count)++] = num;
                num = 0;
                in_number = false;
            }
        }
    }
    for (int i = 0; i < *num_count - 1; i++) {
        for (int j = i + 1; j < *num_count; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int main(void) {
    char str[MAX_LENGTH + 1] = {0};
    int numbers[MAX_LENGTH];
    int num_count = 0;

    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Ошибка открытия файлов: %s\n", strerror(errno));
        if (input_file != NULL) fclose(input_file);
        if (output_file != NULL) fclose(output_file);
        return 1;
    }

    if (fgets(str, MAX_LENGTH + 1, input_file) != NULL) {
        str[strcspn(str, "\r\n")] = '\0';
        extract_and_sort_numbers(str, numbers, &num_count);

        for (int i = 0; i < num_count; i++) {
            fprintf(output_file, "%d", numbers[i]);
            if (i < num_count - 1) {
                fprintf(output_file, " ");
            }
        }
    } else {
        fprintf(stderr, "Ошибка чтения из файла\n");
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}
