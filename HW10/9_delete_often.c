#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_LENGTH 1000

void delete_duplicate(char* str, char* out_str){
    bool seen[256] = { 0 };
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++){
        char tmp = str[i];
        if( tmp != ' ' && !seen[(unsigned char) tmp]){
            seen[(unsigned char)tmp] = true;
            out_str[j++] = tmp;
        }
    }
    out_str[j] = '\0';
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
        delete_duplicate(str, out_str);
        fprintf(output_file, "%s", out_str);
    } else {
        fprintf(stderr, "Ошибка чтения из файла\n");
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}

