#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

#define LED_PORT PORTB
#define LED_DDR  DDRB
#define ADC_CHANNEL 0


void adc_init() {
    ADMUX = (1 << REFS0);
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t adc_read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF8) | (channel & 0x07);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

void display_on_leds(uint8_t value) {
    uint8_t leds = ((value + 1) * 5) / 32;
    LED_PORT = (1 << leds) - 1;
}

int main(void) {
    LED_DDR = 0xFF;
    uart_init();
    adc_init();
    while (1) {
        uint16_t adc_value = adc_read(ADC_CHANNEL);
        uint8_t led_value = adc_value >> 5;
        uart_puti(led_value);
        // display_on_leds(led_value);
        _delay_ms(100);
    }
}
