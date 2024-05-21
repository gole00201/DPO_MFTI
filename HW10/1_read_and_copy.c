/**
 * @file 1_read_and_copy.c
 * @author Volkov Egor
 * @brief Чтение и копирование
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <string.h>
#include <errno.h> /* Выпендриваемся */

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH + 1];
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Ошибка открытия файлов: %s\n", strerror(errno));
        return 1;
    }
    if (fgets(str, MAX_LENGTH + 1, inputFile) != NULL) {
        str[strcspn(str, "\r\n")] = '\0';
        size_t len = strlen(str);
        fprintf(outputFile, "%s, %s, %s %zu\n", str, str, str, len);
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
