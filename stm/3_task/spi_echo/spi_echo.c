/**
 * @file spi_echo.c
 * @author Volkov Egor (gole00201@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-01-20
 * @copyright Copyright (c) 2025
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/spi.h>
#include <stdio.h>
#include <errno.h>

static void
clock_setup(void){
	rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_24MHZ]);
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_GPIOC);
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_AFIO);
	rcc_periph_clock_enable(RCC_USART2);
	rcc_periph_clock_enable(RCC_SPI1);
}

static void
spi_setup(void){
  gpio_set_mode(GPIOA,
                GPIO_MODE_OUTPUT_50_MHZ,
                GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
                GPIO4 | GPIO5 | GPIO7);

  gpio_set_mode(GPIOA,
                GPIO_MODE_INPUT,
                GPIO_CNF_INPUT_FLOAT,
                GPIO6);

  rcc_periph_reset_pulse(RST_SPI1);

  spi_init_master(SPI1,
                  SPI_CR1_BAUDRATE_FPCLK_DIV_64,
                  SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE,
                  SPI_CR1_CPHA_CLK_TRANSITION_2,
                  SPI_CR1_DFF_8BIT,
                  SPI_CR1_MSBFIRST);

  spi_enable_software_slave_management(SPI1);
  spi_set_nss_high(SPI1);
  spi_enable(SPI1);
}

static void
gpio_setup(void){
	gpio_set_mode(GPIOC,
                  GPIO_MODE_OUTPUT_2_MHZ,
		          GPIO_CNF_OUTPUT_PUSHPULL,
                  GPIO13);
}

int
main(void)
{
	int counter = 0;
	uint16_t rx_value = 0x42;

	clock_setup();
	gpio_setup();
	spi_setup();
    // Ne nu eto kaif je voobshe! =)
	while (1) {
        gpio_toggle(GPIOC, GPIO13);
		spi_send(SPI1, (uint8_t) counter);
		rx_value = spi_read(SPI1);
		counter++;
	}

	return 0;
}