#include <stdio.h>
#include <stdlib.h>

typedef struct DA {
    size_t size;
    int* val;
} DA;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int power(int n, int p){
    int ret_val = n;
    if ( p == 0 ){
        return 1;
    }
    for( int i = 1; i < p; i++ ){
        ret_val *= n;
    }
    return ret_val;
}

void append(DA* a, int val) {
    a->val = (int*)realloc(a->val, (a->size + 1) * sizeof(int));
    a->val[a->size] = val;
    a->size++;
}

int cmr(int a, int b){
    return a - b;
}

void sort_by_cmpr(int *a, size_t s, int(*cmpr)(int, int)){
    for(size_t i = 0; i < s; i++){
        for(size_t j = 0; j < s - i - 1; j++){
            if(cmpr(a[j], a[j + 1]) > 0){
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int replace_to_max(int N){
    int res = 0;
    DA array;
    array.val = (int *)malloc(sizeof(int));
    array.size = 0;
    while(N > 0){
        int tmp = N % 10;
        N /= 10;
        append(&array, tmp);
    }
    sort_by_cmpr(array.val, array.size, cmr);
    for(size_t i = 0; i < array.size; i++){
        res += power(10, i) * array.val[i];
    }
    free(array.val);
    return res;
}

int main( void ){
    int num;
    scanf("%d", &num);
    printf("%d\n", replace_to_max(num));
    return 0;
}