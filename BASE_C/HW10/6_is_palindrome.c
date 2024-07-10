/**
 * @file 6_is_palindrome.c
 * @author Volkov Egor
 * @brief Является ли строка палиндромом
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#define MAX_LENGTH 1000

bool is_palindrome(const char* str){
    for(size_t i = 0; i < strlen(str) / 2; i++){
        if(str[i] != str[strlen(str) - 1 - i]){
            return 0;
        }
    }
    return 1;
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
        if(is_palindrome(str1)){
            fprintf(output_file, "YES");
        } else {
            fprintf(output_file, "NO");
        }
    } else {
        fprintf(stderr, "Ошибка чтения из файла\n");
    }


    return 0;
}