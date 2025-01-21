#ifndef HC595
#define HC595
#include <avr/io.h>
#include "stddef.h"
#include <util/delay.h>

struct hc595 {
    volatile uint8_t *port;
    volatile uint8_t *ddr;
    uint8_t sck;
    uint8_t latch;
    uint8_t data;
}typedef hc595;


void register_init(hc595 *ctx);
void register_send_byte(hc595 *ctx, uint8_t byte);

#endif