#include <stdio.h>
#include <stdint.h>

uint32_t _pow(uint32_t n, uint32_t p){
    uint32_t res = 1;
    for(uint32_t i = 0; i < p; i++){
        res *= n;
    }
    return res;
}

int
main( void ){
    uint32_t n, k, max, res;
    scanf("%u %u", &n, &k);
    uint32_t mask = _pow(2, k) - 1;
    max = n & mask;
    for(int i = 1; i < 31; i++){
        uint32_t current = (n >> i) & mask;
        if(max < current){
            max = current;
        }
    }
    printf("%u\n", max);
    return 0;
}