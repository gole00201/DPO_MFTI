#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#define MAX_LENGTH 1000

void fprintf_each_word(char* str, FILE* output_file) {
    char* word_start = NULL;
    bool in_word = false;
    while (*str) {
        if (*str != ' ' && !in_word) {
            in_word = true;
            word_start = str;
        } else if (*str == ' ' && in_word) {
            in_word = false;
            while (word_start != str) {
                fputc(*word_start++, output_file);
            }
            fputc('\n', output_file);
        }
        str++;
    }
    if (in_word) {
        while (*word_start && *word_start != ' ') {
            fputc(*word_start++, output_file);
        }
        fputc('\n', output_file);
    }
}

int main(void) {
    char str[MAX_LENGTH + 1] = {0};
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
        fprintf_each_word(str, output_file);
    } else {
        fprintf(stderr, "Ошибка чтения из файла\n");
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}
