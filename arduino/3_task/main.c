#include <avr/io.h>
#include <util/delay.h>
#include "bmp180.h" // Не мое
#include "i2c.h" // Не мое
#include "uart.h" // Мое

#define SEGMENT_PORT_TENS PORTD
#define SEGMENT_DDR_TENS  DDRD
#define SEGMENT_PORT_ONEC PORTB
#define SEGMENT_DDR_ONEC DDRB

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


void display_tens(uint8_t value) {
    SEGMENT_PORT_TENS = digit[value];
}

void display_ones(uint8_t value) {
    SEGMENT_PORT_ONEC = (digit[value] >> 1);
    if (digit[value] & 1) {
        SEGMENT_PORT_TENS |= (1 << PB7);
    }
}

int main(void) {
    SEGMENT_DDR_TENS = 0xFF;
    SEGMENT_DDR_ONEC = 0xFF;

    int16_t temperature = 0;
    Bmp180CalibrationData calibrationData;
    // https://github.com/radionoise/avr-bmp180/
    // Рабочая библиотека со своим I2C
    // Датчик бракованный нещадно. Но изменение температуры хотя бы ловит.
    // В поле с давлением вообще лучше не забираться.
    uint8_t result = bmp180ReadCalibrationData(&calibrationData);
    if (result == BMP180_OK) {
        Bmp180Data bmp180Data;
        uint8_t counter = 0;
        while (1) {
            if (counter == 50) {
                result = bmp180ReadData(BMP180_OSS_STANDARD, &bmp180Data, &calibrationData);
                if (result == BMP180_OK) {
                    temperature = bmp180Data.temperatureC;  // Убираем сдвиг
                }
                counter = 0;
            }
            uint8_t tens = temperature / 10;
            uint8_t ones = temperature % 10;
            display_tens(tens);
            display_ones(ones);
            counter++;
            _delay_ms(10);
        }
    }
    return 0;
}