void sort_even_odd(int n, int a[]) {
    int even_cnt = 0;
    int sorted[n];
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            sorted[even_cnt++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            sorted[even_cnt++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = sorted[i];
    }
}