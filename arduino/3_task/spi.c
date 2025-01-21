#include "spi.h"

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
void spi_init(uint8_t mode, uint8_t speed, uint8_t data_order) {
    // Настройка пинов
    SPI_DDR |= (1 << SPI_MOSI_PIN) | (1 << SPI_SCK_PIN) | (1 << SPI_SS_PIN);  // Мастеру необходимы эти пины
    SPI_DDR &= ~(1 << SPI_MISO_PIN); // MISO - вход

    // Настройка режима SPI
    SPCR = (1 << SPE) | (1 << MSTR) | (mode & 0x03); // Включить SPI, настроить на мастер и выбранный режим (CPOL, CPHA)
    if (data_order) {
        SPCR |= (1 << DORD); // Если младший бит сначала
    } else {
        SPCR &= ~(1 << DORD); // Если старший бит сначала
    }

    // Устанавливаем скорость передачи данных
    if (speed == 0) {
        SPSR &= ~(1 << SPI2X);  // Скорость делителя SPI: Fosc/4
    } else {
        SPSR |= (1 << SPI2X);   // Скорость делителя SPI: Fosc/2
    }
}

// Передача данных по SPI (блокирующая)
void spi_transmit(uint8_t data) {
    SPDR = data; // Передаем данные в регистр данных
    while (!(SPSR & (1 << SPIF))); // Ожидаем окончания передачи
}

// Прием данных по SPI (блокирующая)
uint8_t spi_receive(void) {
    while (!(SPSR & (1 << SPIF))); // Ожидаем, пока данные не будут приняты
    return SPDR; // Возвращаем принятые данные
}

// Функция для отправки и получения данных одновременно
uint8_t spi_transceive(uint8_t data) {
    SPDR = data; // Передаем данные в регистр
    while (!(SPSR & (1 << SPIF))); // Ожидаем окончания передачи
    return SPDR; // Возвращаем принятые данные
}