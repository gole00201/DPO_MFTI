/**
 * @file 20_odd_and_not_odd.c
 * @author Volkov Egor
 * @brief Произведение цифр тех... этих... с этими.. потому что эти... эти..
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#define SIZE 10

void get_array(int* a, size_t s){
    for(size_t i = 0; i < s; i++){
        scanf("%d", (a + i));
    }
}

void put_array(int* a, size_t s){
    for(size_t i = 0; i < s; i++){
        printf("%d ", *(a + i));
    }
}


int cnt_odd(int* a, size_t s){
    int cnt = 0;
    for(int i = 0; i < s; i++){
        if(a[i] % 2 == 0){
            cnt++;
        }
    }
    return cnt;
}

int cnt_not_odd(int* a, size_t s){
    int cnt = 0;
    for(int i = 0; i < s; i++){
        if(a[i] % 2 != 0){
            cnt++;
        }
    }
    return cnt;
}

int mul_of_not_odd_dig(int num){
    int mul = 1;
    while( num != 0 ){
        int tmp = num % 10;
        if( tmp % 2 != 0 ){
            mul *= tmp;
        }
        num /= 10;
    }
    return mul;
}

int mul_of_odd_dig(int num){
    int mul = 1;
    while( num != 0 ){
        int tmp = num % 10;
        if( tmp % 2 == 0 ){
            mul *= tmp;
        }
        num /= 10;
    }
    return mul;
}


void change_to_mul_of_not_odd_array(int* a, size_t s){
    for(int i = 0; i < s; i++){
        if(a[i] % 2 != 0){
            a[i] = mul_of_not_odd_dig(a[i]);
        }
    }
}

void change_to_mul_of_odd_array(int* a, size_t s){
    for(int i = 0; i < s; i++){
        if(a[i] % 2 == 0){
            a[i] = mul_of_odd_dig(a[i]);
        }
    }
}

int main( void ){
    int a[SIZE] = {0};
    get_array(a, SIZE);
    int odd = cnt_odd(a, SIZE);
    int not_odd = cnt_not_odd(a, SIZE);
    if(odd > not_odd){
        change_to_mul_of_not_odd_array(a, SIZE);
    } else {
        change_to_mul_of_odd_array(a, SIZE);
    }
    put_array(a, SIZE);
    printf("\n");
    return 0;
}