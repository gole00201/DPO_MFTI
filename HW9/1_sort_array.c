void sort_array(int s, int *a){
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s - i - 1; j++){
            if(a[j] - a[j + 1] > 0){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
