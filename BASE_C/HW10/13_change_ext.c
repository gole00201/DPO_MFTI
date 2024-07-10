#include <stdio.h>
#include <string.h>
#include <errno.h>
#define MAX_LENGTH 1000

int get_pos_for_insert(char* str){
    for(int i = strlen(str) - 1; i > 0; i--){
        if( str[i] == '.' ){
            return i;
        }
        if( str[i] == '/' ){
            return strlen(str);
        }
    }
    return strlen(str);
}

void insert_at_pos(char* str, char* src, int pos){
    while(*str){
        *(str + pos) = *src;
        str++, src++;
    }
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
        int pos = get_pos_for_insert(str);
        insert_at_pos(str, ".html", pos);
        fprintf(output_file, "%s", str);
    } else {
        fprintf(stderr, "Ошибка чтения файла");
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}