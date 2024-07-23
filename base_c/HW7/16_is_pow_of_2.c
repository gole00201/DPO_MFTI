#include <stdio.h>

int is_power_of_2(int n){
    if( n == 0 || n == 2 ){
        return 1;
    }
    if( n % 2 == 0 || n == 1){
        is_power_of_2(n / 2);
    } else {
        return 0;
    }
}

int main( void ){
    int n;
    scanf("%d", &n);
    if( is_power_of_2(n) ){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}