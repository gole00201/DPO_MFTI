#include <stdio.h>

int main() {
    int N, num;
    int max, count;
    scanf("%d", &N);
    if (N <= 0) {
        return 1;
    }
    scanf("%d", &num);
    max = num;
    count = 1;
    for (int i = 1; i < N; i++) {
        scanf("%d", &num);

        if (num > max) {
            max = num;
            count = 1;
        } else if (num == max) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
