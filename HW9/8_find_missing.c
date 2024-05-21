/**
 * @file 8_find_missing.c
 * @author Volkov Egor
 * @brief Поиск пропущенного числа
 * @version 0.1
 * @date 2024-05-21
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <stdlib.h>

int find_missing_number(int *arr, int size) {
    int sum = 0;
    int real_sum = 0;
    int M = 1001, N = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            break;
        }
        if (arr[i] < M) {
            M = arr[i];
        }
        if (arr[i] > N) {
            N = arr[i];
        }
        real_sum += arr[i];
    }
    sum = (N * (N + 1)) / 2 - ((M - 1) * M) / 2;
    return sum - real_sum;
}

int main() {
    int *arr = NULL;
    int capacity = 10;
    int size = 0;
    arr = (int *)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        return 1;
    }
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        if (size >= capacity) {
            capacity *= 2;
            int *temp = realloc(arr, capacity * sizeof(int));
            arr = temp;
        }
        arr[size++] = num;
    }
    int missing_number = find_missing_number(arr, size);
    printf("%d\n", missing_number);
    free(arr);
    return 0;
}