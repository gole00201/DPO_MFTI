#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    char str1[10005], str2[10005];
    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int maxPrefixSuffix = 0;  // Для первого числа
    int maxSuffixPrefix = 0;  // Для второго числа

    // 1. Поиск максимального префикса первой строки, являющегося суффиксом второй
    for (int i = 1; i <= min(len1, len2); i++) {
        if (strncmp(str1, str2 + len2 - i, i) == 0) {
            maxPrefixSuffix = i;
        }
    }

    // 2. Поиск максимального суффикса первой строки, являющегося префиксом второй
    for (int i = 1; i <= min(len1, len2); i++) {
        if (strncmp(str1 + len1 - i, str2, i) == 0) {
            maxSuffixPrefix = i;
        }
    }

    printf("%d %d\n", maxPrefixSuffix, maxSuffixPrefix);

    return 0;
}
