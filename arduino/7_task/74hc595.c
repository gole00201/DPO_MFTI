#include "74hc595.h"

void register_init(hc595 *ctx){
    SETBIT(*(ctx->ddr), ctx->data);
    SETBIT(*(ctx->ddr), ctx->sck);
    SETBIT(*(ctx->ddr), ctx->latch);

    CLRBIT(*(ctx->port), ctx->data);
    CLRBIT(*(ctx->port), ctx->sck);
    CLRBIT(*(ctx->port), ctx->latch);
}

void register_send_byte(hc595 *ctx, uint8_t byte) {
    for (uint8_t i = 0; i < 8; i++) {
        if (byte & (1 << (7 - i))) {
            SETBIT(*(ctx->port), ctx->data);
        } else {
            CLRBIT(*(ctx->port), ctx->data);
        }
        SETBIT(*(ctx->port), ctx->sck);
        _delay_us(1);
        CLRBIT(*(ctx->port), ctx->sck);
    }

    SETBIT(*(ctx->port), ctx->latch);
    _delay_us(1);
    CLRBIT(*(ctx->port), ctx->latch);
}