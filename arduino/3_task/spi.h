#ifndef SPI_H
#define SPI_H

#include <avr/io.h>

// Определения пинов
#define SPI_DDR         DDRB    // Директория для данных
#define SPI_PORT        PORTB   // Порт для данных
#define SPI_MISO_PIN    PB4     // Мастер-Вход-Рабочий-Выход
#define SPI_MOSI_PIN    PB3     // Мастер-Выход-Рабочий-Вход
#define SPI_SCK_PIN     PB5     // Синхронизирующий тактировочный сигнал
#define SPI_SS_PIN      PB2     // Сигнал выбора ведомого устройства

// Режимы работы SPI
#define SPI_MODE0  0x00    // CPOL=0, CPHA=0
#define SPI_MODE1  0x01    // CPOL=0, CPHA=1
#define SPI_MODE2  0x02    // CPOL=1, CPHA=0
#define SPI_MODE3  0x03    // CPOL=1, CPHA=1

// Базовые настройки SPI
void spi_init(uint8_t mode, uint8_t speed, uint8_t data_order);
void spi_transmit(uint8_t data);
uint8_t spi_receive(void);
uint8_t spi_transceive(uint8_t data);

#endif
