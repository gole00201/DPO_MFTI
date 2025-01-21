#include <avr/io.h>
#include <util/delay.h>
#include "stddef.h"
#include <avr/interrupt.h>

long int cnt_tick = 0;
long int cnt_int = 0;

ISR(INT0_vect){
    if ((long int)cnt_tick - (long int)cnt_int > 100){
        PORTD ^= (1 << PD3);
    }
    cnt_int = (long int)cnt_tick;
}

void
setup(void){
    SETBIT(DDRB, PB5);
    SETBIT(DDRD, PD3);

    CLRBIT(DDRD, PD2);
    SETBIT(PORTD, PD2); // PULL UP
    EICRA |= (1 << ISC00);
    EIMSK |= (1 << INT0);
    sei();
}


int
main(void){
    setup();
    while(1){
        cnt_tick++;
    }
    return 0;
}