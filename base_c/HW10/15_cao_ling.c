#include <stdio.h>
#include <string.h>
#include <errno.h>
#define MAX_LENGTH 1000


void swap_words(char* src, char* word_ts, char* word_fs){
    char buffer[MAX_LENGTH + 1] = {'\0'};
    char *pos;
    int old_len = strlen(word_ts);
    int new_len = strlen(word_fs);
    int len = 0;
    char* cur_pos = src;
    while ((pos = strstr(cur_pos, word_ts)) != NULL)
    {
        strncat(buffer, cur_pos, pos - cur_pos);
        len += pos - cur_pos;
        strcat(buffer, word_fs);
        len += new_len;
        cur_pos = pos + old_len;
    }
    strcat(buffer, cur_pos);
    strcpy(src, buffer);
}

int main( void ){
    char str[MAX_LENGTH + 1] = {'\0'};
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");
    if( input_file == NULL || output_file == NULL ){
        fprintf(stderr, "Ошибка открытия файла: %s", strerror(errno));
        fclose(input_file);
        fclose(output_file);
        return 1;
    }
    if(fgets(str, MAX_LENGTH + 1, input_file) != NULL){
        str[strcspn(str, "\r\n")] = '\0';
        swap_words(str, "Cao", "Ling");
        fprintf(output_file, "%s", str);
    } else {
        fprintf(stderr, "Ошибка чтения файла");
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}