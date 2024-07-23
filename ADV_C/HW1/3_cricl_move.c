#include <stdio.h>
#include <stdint.h>

uint32_t move_r(uint32_t n, int k){
    uint32_t res = 0;
    res = (n >> k) | (n << (32 - k));
    return res;
}

int
main(){
    uint32_t n, k;
    scanf("%d %d", &n, &k);
    printf("%lu\n", move_r(n, k));
    return 0;
}