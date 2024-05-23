#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_LENGTH 1000


void get_longest_word(const char* str, char* out_str) {
    int max_len = 0;
    int cur_len = 0;
    const char* max_word = NULL;
    const char* cur_word = str;

    while (*str) {
        if (*str != ' ') {
            if (cur_len == 0) {
                cur_word = str;
            }
            cur_len++;
        } else {
            if (cur_len > max_len) {
                max_len = cur_len;
                max_word = cur_word;
            }
            cur_len = 0;
        }
        str++;
    }
    if (cur_len > max_len) {
        max_len = cur_len;
        max_word = cur_word;
    }

    if (max_word) {
        strncpy(out_str, max_word, max_len);
        out_str[max_len] = '\0';
    }
}


int main(void) {
    char str[MAX_LENGTH + 1] = {0};
    char out_str[MAX_LENGTH + 1] = {0};
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
        get_longest_word(str, out_str);
        fprintf(output_file, "%s", out_str);
    } else {
        fprintf(stderr, "Ошибка чтения из файла\n");
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}