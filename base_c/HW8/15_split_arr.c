/**
 * @file 15_split_arr.c
 * @author Volkov Egor
 * @brief На динамических массивах, потому что захотелось =)
 * @version 0.1
 * @date 2024-05-10
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct DA {
    size_t size;
    int* val;
} DA;

typedef struct TWO_ARR {
    DA p;
    DA n;
} TWO_ARR;

void get_array(int* a, size_t s) {
    for (size_t i = 0; i < s; i++) {
        scanf("%d", (a + i));
    }
}

void put_array(int* a, size_t s) {
    for (size_t i = 0; i < s; i++) {
        printf("%d ", *(a + i));
    }
}

void append(DA* a, int val) {
    a->val = (int*)realloc(a->val, (a->size + 1) * sizeof(int));
    a->val[a->size] = val;
    a->size++;
}

TWO_ARR two_arr_by_s(int* a, size_t s) {
    TWO_ARR arrs = { {0}, {0} };
    arrs.n.val = (int*)malloc(sizeof(int));
    arrs.p.val = (int*)malloc(sizeof(int));
    arrs.n.size = 0;
    arrs.p.size = 0;
    for (size_t i = 0; i < s; i++) {
        if (a[i] > 0) {
            append(&arrs.p, a[i]);
        } else if (a[i] < 0) {
            append(&arrs.n, a[i]);
        }
    }
    return arrs;
}

int main(void) {
    int a[SIZE] = {0};
    get_array(a, SIZE);
    TWO_ARR res = two_arr_by_s(a, SIZE);
    put_array(res.p.val, res.p.size);
    put_array(res.n.val, res.n.size);
    printf("\n");
    free(res.p.val);
    free(res.n.val);
    return 0;
}
