#include <avr/io.h>
#include "stddef.h"
#include <util/setbaud.h>
#include "uart.h"
#include "blink.h"

void uart_init(void) {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    #if USE_2X
        UCSR0A |= (1 << U2X0);
    #else
        UCSR0A &= ~(1 << U2X0);
    #endif

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);

    CLRBIT(UCSR0B, UCSZ02);
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);

}

void uart_ping(void) {
    while (!(UCSR0A & (1<<UDRE0))) {
        blink_twice();
    }
    UDR0 = 'x';
}

void uart_echo(void) {
    if (!BITSET(UCSR0A, RXC0)) {
        return;
    }
    if (!BITSET(UCSR0A, UDRE0)) {
        return;
    }
    UDR0 = UDR0;
}


uint8_t uart_getc(void) {
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

void uart_gets(char *buffer, uint8_t size) {
    uint8_t nextChar;
    uint8_t stringLen = 0;
    nextChar = uart_getc();
    while (nextChar != '\n' && stringLen < size - 1)
    {
        *buffer++ = nextChar;
        stringLen++;
        nextChar = uart_getc();
    }
    *buffer = '\0';
}

void uart_putc(unsigned char c) {
    while (!BITSET(UCSR0A, UDRE0)) {
    }
    UDR0 = c;
}

void uart_puts(char *s) {
    while(*s != '\0') {
        uart_putc(*s++);
    }
}


void uart_puti(int num) {
    char buffer[10]; // Буфер для строки (максимум 10 символов с учетом знака)
    char *ptr = &buffer[9];
    *ptr = '\0'; // Завершающий нуль

    if (num == 0) {
        uart_putc('0');
        return;
    }
    if (num < 0) {
        uart_putc('-');
        num = -num;
    }

    while (num > 0) {
        *(--ptr) = (num % 10) + '0';
        num /= 10;
    }

    uart_puts(ptr);
}