/**
 * @file 3_read_1000.c
 * @author Volkov Egor
 * @brief Чтение и нахождение савпадений
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <string.h>
#include <errno.h> /* Выпендриваемся */

#define MAX_LENGTH 1000

int main() {
    char str[MAX_LENGTH + 1];
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Ошибка открытия файлов: %s\n", strerror(errno));
        return 1;
    }
    if (fgets(str, MAX_LENGTH + 1, input_file) != NULL) {
        str[strcspn(str, "\r\n")] = '\0';
        size_t len = strlen(str);
        for(size_t i = 0; i < len - 1; i++){
            if(str[i] == str[len - 1]){
                fprintf(output_file, "%zu ", i);
            }
        }
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}
