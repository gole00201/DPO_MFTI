void swap_negmax_last(int size, int a[]) {
    int it = -1;
    int last_index = size - 1;
    for (int i = 0; i < size; i++) {
        if (a[i] < 0 && (it == -1 || a[i] > a[it])) {
            it = i;
        }
    }
    if (it != -1) {
        int temp = a[it];
        a[it] = a[last_index];
        a[last_index] = temp;
    }
}