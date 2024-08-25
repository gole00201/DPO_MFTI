#include <stdio.h>
#include <string.h>

/* На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки.
Каждая из строк не превышает по длине 104. В строках не встречаются пробельные символы.
На стандартный поток вывода напечатайте два числа, разделённых пробелом: первое число — длина наибольшего префикса первой строки,
являющегося суффиксом второй; второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксом второй.
Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны). */


int max_prefix_suffix(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int max_len = 0;
    for (int i = 1; i <= len1 && i <= len2; i++) {
        if (strncmp(s1, s2 + len2 - i, i) == 0) {
            max_len = i;
        }
    }
    return max_len;
}

int max_suffix_prefix(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int max_len = 0;

    for (int i = 1; i <= len1 && i <= len2; i++) {
        if (strncmp(s1 + len1 - i, s2, i) == 0) {
            max_len = i;
        }
    }
    return max_len;
}

int main() {
    char s1[104];
    char s2[104];

    scanf("%s", s1);
    scanf("%s", s2);

    int prefix_suffix_len = max_prefix_suffix(s1, s2);
    int suffix_prefix_len = max_suffix_prefix(s1, s2);

    printf("%d %d\n", prefix_suffix_len, suffix_prefix_len);

    return 0;
}
