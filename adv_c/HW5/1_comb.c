#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM_LEN 100

/* Сколько различных трехзначных чисел можно получить из заданного натурального N, вычеркивая цифры из его десятичной записи?
Формат данных на входе: Единственное натуральное число N, не превосходящее 10100.
Формат данных на выходе: Единственное целое число – найденное количество. */


bool isUnique(int number, int *uniqueNumbers, int count) {
    for (int i = 0; i < count; i++) {
        if (uniqueNumbers[i] == number) {
            return false;
        }
    }
    return true;
}

int main() {
    char N[MAX_NUM_LEN];
    scanf("%s", N);
    int length = strlen(N);
    int uniqueNumbers[MAX_NUM_LEN * MAX_NUM_LEN] = {0};
    int uniqueCount = 0;
    for (int i = 0; i < length - 2; i++) {
        for (int j = i + 1; j < length - 1; j++) {
            for (int k = j + 1; k < length; k++) {
                int number = (N[i] - '0') * 100 + (N[j] - '0') * 10 + (N[k] - '0');
                if (isUnique(number, uniqueNumbers, uniqueCount)) {
                    uniqueNumbers[uniqueCount++] = number;
                }
            }
        }
    }
    printf("%d\n", uniqueCount);
    return 0;
}
