/**
 * @file 19_cnt_a_int_str.c
 * @author Volkov Egor
 * @brief Подсчет кол-ва 'a'
 * @version 0.1
 * @date 2024-05-05
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>

int cnt_a(int cnt){
    char c;
    if( (c = getchar()) == 'a' ){
        return cnt_a(++cnt);
    } else if( c == '.' ){
        return cnt;
    } else{
        return cnt_a(cnt);
    }

}

int main( void ){
    printf("%d\n", cnt_a(0));
    return 0;
}