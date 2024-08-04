#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 10

void count_digits(const char *str, int *heat_map) {
    for (const char *p = str; *p; p++) {
        if (*p >= '0' && *p <= '9') {
            heat_map[*p - '0']++;
        }
    }
}

unsigned long long choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

int count_unique_3_digit_numbers(const char *str) {
    int heat_map[MAX_DIGITS] = {0};
    int digits[MAX_DIGITS];
    int num_digits = 0;

    count_digits(str, heat_map);
    for (int i = 0; i < MAX_DIGITS; i++) {
        if (heat_map[i] > 0) {
            digits[num_digits++] = i;
        }
    }

    if(num_digits == 1){
        return 1;
    }
    if(num_digits == 2){
        return 4;
    }

    return choose(num_digits, 3);
}

int main(void) {
    char input[101];
    scanf("%100s", input);
    printf("%d\n", count_unique_3_digit_numbers(input));
    return 0;
}
