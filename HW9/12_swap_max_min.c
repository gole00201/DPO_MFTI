void change_max_min(int size, int* a){
    int min = a[0];
    int max = a[0];
    int max_it = 0;
    int min_it = 0;
    for(int i = 0; i < size; i++){
        if( a[i] < min ){
            min = a[i];
            min_it = i;
        }
        if( a[i] > max ){
            max = a[i];
            max_it = i;
        }
    }
    if(max_it != min_it){
        int tmp = a[max_it];
        a[max_it] = a[min_it];
        a[min_it] = tmp;
    }
}
