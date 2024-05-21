/**
 * @file 10_collapse_str.c
 * @author Volkov Egor
 * @brief Ужимка строки с цифрами
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <string.h>

void collaps_str(const char input[], char output[]) {
    int input_length = strlen(input);
    int output_index = 0;
    for (int i = 0; i < input_length - 1; ) {
        char current_char = input[i];
        int count = 1;
        while (i + count < input_length && input[i + count] == current_char) {
            count++;
        }
        output[output_index++] = current_char;
        int num_chars_written = sprintf(output + output_index, "%d", count);
        output_index += num_chars_written;
        i += count;
    }
    output[output_index] = '\0';
}

int main() {
    char input[1001];
    char output[2002];
    scanf("%s", input);
    collaps_str(input, output);
    printf("%s\n", output);
    return 0;
}