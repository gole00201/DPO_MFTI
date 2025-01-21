#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "74hc595.h"

#define LEDS_PORT PORTB
#define LEDS_DDR DDRB

const uint8_t digit[] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};


int main(void) {
    LEDS_DDR = 0xFF;
    LEDS_PORT = 0x00;
    uint8_t cnt = 1;
    hc595 shift_reg_one = {
        .port = &PORTD,
        .ddr = &DDRD,
        .data = PD0,
        .sck = PD1,
        .latch = PD2
    };
    register_init(&shift_reg_one);
    while(1){
        LEDS_PORT = cnt;
        register_send_byte(&shift_reg_one, digit[cnt % 10]);
        cnt = cnt << 1;
        if(cnt > 16){
            cnt = 1;
        }
        _delay_ms(1000);
    }
    return 0;
}