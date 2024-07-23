#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#define MAX_LENGTH 10000

typedef struct ANSWER_t
{
    int sml_case;
    int big_case;
}ANSWER_t;


ANSWER_t cnt_cases(char* str){
    ANSWER_t res = {
        .sml_case = 0,
        .big_case = 0
    };
    while(*str != '\0'){
        if(*str >= 'a' && *str <= 'z'){
            res.sml_case++;
        }
        if(*str >= 'A' && *str <= 'Z'){
            res.big_case++;
        }
        str++;
    }
    return res;
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
        ANSWER_t res = cnt_cases(str1);
        fprintf(output_file, "%d %d", res.sml_case, res.big_case);
    } else {
        fprintf(stderr, "Ошибка чтения из файла\n");
    }


    return 0;
}