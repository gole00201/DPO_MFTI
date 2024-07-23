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

int main(void){
    uint32_t n, k;
    scanf("%u %u", &n, &k);
    printf("%u\n", get_mask(n, k));
    return 0;
}
