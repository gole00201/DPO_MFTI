/**
 * @file 6_rev_string.c
 * @author Volkov Egor
 * @brief Реверс строки рекурсивно
 * @version 0.1
 * @date 2024-05-04
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>


void rev_print_str(){
    char c;
    if( (c = getchar()) != '.'){
        rev_print_str();
        printf("%c", c);
    }
}


int main( void ){
    rev_print_str();
    return 0;
}