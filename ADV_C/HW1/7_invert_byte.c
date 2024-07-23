#include <stdio.h>
#include <stdint.h>

int
main( void ){
    uint32_t n = 0;
    scanf("%u", &n);
    uint32_t mask = 0xFF000000;
    n = n ^ mask;
    printf("%u\n", n);
    return 0;
}