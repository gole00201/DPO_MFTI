#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#define MAX_LENGTH 1000

int is_digit(char c){
    return (c >= '0' && c <= '9');
}


/*
    !TODO: Доделать -_-
*/
void fprintf_only_digits(FILE* output, char* str){
    int is_thirst = 1;
    while(*str != '\0'){
        if(is_digit(*str)){
            is_thirst = 0;
            fprintf(output, "%c", *str);
        }
        if(!is_thirst){
            fprintf(output, " ");
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
        fclose(input_file);
        fclose(output_file);
        return 1;
    }
    if (fgets(str1, MAX_LENGTH + 1, input_file) != NULL) {
        str1[strcspn(str1, "\r\n")] = '\0';
    } else {
        fprintf(stderr, "Ошибка чтения из файла\n");
    }


    return 0;
}