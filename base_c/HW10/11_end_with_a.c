#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_LENGTH 1000

int get_cnt_words_with_end_a(char* str){
    int cnt = 0;
    while(*str){
        if(*str == 'a' && (*(str + 1) == ' ' || *(str + 1) == '\0')){
            cnt++;
        }
        str++;
    }
    return cnt;
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
        int res = get_cnt_words_with_end_a(str);
        fprintf(output_file, "%d", res);
    } else {
        fprintf(stderr, "Ошибка чтения из файла\n");
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}