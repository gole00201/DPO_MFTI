/**
 * @file 5_a_to_b.c
 * @author Volkov Egor
 * @brief Замена А на Б и Б на А
 * @version 0.1
 * @date 2024-05-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string.h>
#include <stdio.h>
#include <errno.h> /* Флексим =) */
#define MAX_LENGTH 1000

void swap_a_to_b(char* str){
    while(*str != '\0'){
        switch (*str)
        {
        case 'A':
            *str = 'B';
            break;
        case 'B':
            *str = 'A';
            break;
        case 'b':
            *str = 'a';
            break;
        case 'a':
            *str = 'b';
            break;
        default:
            break;
        }
        str++;
    }
}

int main( void ){
    char str1[MAX_LENGTH + 1] = {0};
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Ошибка открытия файлов: %s\n", strerror(errno));
        if (input_file != NULL) fclose(input_file);
        if (output_file != NULL) fclose(output_file);
        return 1;
    }

    if (fgets(str1, MAX_LENGTH + 1, input_file) != NULL) {
        str1[strcspn(str1, "\r\n")] = '\0';
        swap_a_to_b(str1);
        fprintf(output_file, "%s", str1);
    } else {
        fprintf(stderr, "Ошибка чтения из файла\n");
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}
