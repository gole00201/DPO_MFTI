#include <stdio.h>
#include <string.h>

void count_digits(const char *number) {
    int digit_count[10] = {0};
    for (int i = 0; i < strlen(number); i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            digit_count[number[i] - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (digit_count[i] > 0) {
            printf("%d %d\n", i, digit_count[i]);
        }
    }
}

int main() {
    char number[1001];
    scanf("%1000s", number);
    count_digits(number);
    return 0;
}