#include <stdio.h>
#include <stdlib.h>


void
get_array(int* a, size_t s){
    for(size_t i = 0; i < s; i++){
        scanf("%d", (a + i));
    }
}

int
imax(int* a, int cnt){
    int max = a[0];
    for(size_t i = 1; i < cnt; i++){
        if( a[i] > max ){
            max = a[i];
        }
    }
    return max;
}

int
cnt_n(int* a, int cnt, int val){
    int ret_val = 0;
    for(size_t i = 0; i < cnt; i++){
        if(a[i] == val){
            ret_val++;
        }
    }
    return ret_val;
}

int
main( void ){
    int cnt;
    scanf("%d", &cnt);
    int* a = (int *)malloc(sizeof(int) * cnt);
    get_array(a, cnt);
    int max = imax(a, cnt);
    int res = cnt_n(a, cnt, max);
    printf("%d\n", res);
    free(a);
    return 0;
}