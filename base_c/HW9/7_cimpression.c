int compression(int a[], int b[], int N) {
    if (N == 0) {
        return 0;
    }
    int count = 0;
    int b_index = 0;
    if (a[0] != 0) {
        b[b_index++] = 0;
    }
    int current = a[0];
    for (int i = 0; i < N; i++) {
        if (a[i] == current) {
            count++;
        } else {
            b[b_index++] = count;
            count = 1;
            current = a[i];
        }
    }
    b[b_index++] = count;
    return b_index;
}
