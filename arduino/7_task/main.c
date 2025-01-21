#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"

int btn_cnt = 0;
ISR(INT0_vect){
    cli();
    uart_puti(btn_cnt);
    uart_putc('\n');
    btn_cnt++;
    sei();
}

int main(void) {
    uart_init();
    DDRD &= ~(1 << PD2);
    EICRA |= (1 << ISC00);
    EIMSK |= (1 << INT0);
    DDRB |= (1 << PB5);
    sei();
    while(1){
        PORTB ^= (1 << PB5);
        _delay_ms(500);
    }
    return 0;
}