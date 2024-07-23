#include <stdio.h>
#include <stdint.h>


int
main( void ){
    uint32_t n;
    scanf("%u", &n);
    int res = __builtin_popcount(n);
    printf("%d\n", res);
    return 0;
}