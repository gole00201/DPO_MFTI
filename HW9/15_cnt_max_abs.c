int count_bigger_abs(int n, int a[]){
    int max = a[0];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if( a[i] > max ){
            max = a[i];
        }
    }
    for(int i = 0; i < n; i++){
        if( (a[i] >= 0 ? a[i] : -1 * a[i]) > max){
            cnt++;
        }
    }
    return cnt;
}