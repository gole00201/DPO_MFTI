/**
 * @file 2_read_num_from_file.c
 * @author Volkov Egor
 * @brief Алфавит с цифрами =)
 * @version 0.1
 * @date 2024-05-21
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    int num;
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Ошибка открытия файлов: %s\n", strerror(errno));
        return 1;
    }
    if (fscanf(input_file, "%d", &num) != 1 || num % 2 != 0 || num > 26) {
        fprintf(stderr, "Ошибка чтения числа или число не соответствует условиям\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }
    int char_cnt = 0;
    int dec_cnt = 2;
    for (int i = 0; i < num; i++) {
        if (i % 2 == 0) {
            fprintf(output_file, "%c", 'A' + char_cnt++);
        } else {
            fprintf(output_file, "%d", dec_cnt);
            dec_cnt += 2;
            if (dec_cnt > 8) {
                dec_cnt = 2;
            }
        }
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}
