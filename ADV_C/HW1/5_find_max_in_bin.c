#include <stdio.h>
#include <stdint.h>

uint32_t _pow(uint32_t n, uint32_t p){
    uint32_t res = 1;
    for(uint32_t i = 0; i < p; i++){
        res *= n;
    }
    return res;
}

uint32_t get_mask(uint32_t n, uint32_t k){
    return (_pow(2, k) - 1) & n;
}

int
main( void ){
    uint32_t n, k, max, res;
    scanf("%u %u", &n, &k);
    uint32_t mask = _pow(2, k) - 1;
    for(int i = 0; i < 32; i++){
        if((n >> i) & 0x1){
            max = i;
        }
    }
    res = (n & (mask << (max - (k - 1)))) >> (max - (k - 1));
    printf("%u\n", res);
    return 0;
}