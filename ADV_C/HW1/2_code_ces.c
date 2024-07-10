#include <stdio.h>

int main() {
    int N;
    char c;
    scanf("%d", &N);
    while (scanf("%c", &c) && c != '.') {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + N) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + N) % 26;
        }
        putchar(c);
    }
    printf(".\n");
    return 0;
}