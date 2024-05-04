#include <stdio.h>

double pow_r(double n, double p){
    if( p == 0 ){
        return 1;
    }
    if( p == 1 ){
        return n;
    } else {
        return pow_r(n, p - 1) * n;
    }
}

int main( void ){
    double n, p;
    scanf("%lf %lf", &n, &p);
    printf("%.0lf\n", pow_r(n, p));
    return 0;
}