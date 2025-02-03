/**
 * @file uart.c
 * @author Volkov Egor (gole00201@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-02-03
 * @copyright Copyright (c) 2025
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/exti.h>

#define LED_PORT    GPIOC
#define LED_PIN     GPIO13
#define BTN_PORT    GPIOA
#define BTN_PIN     GPIO0

static void
clock_setup(void) {
    rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOC);
    rcc_periph_clock_enable(RCC_AFIO);
    rcc_periph_clock_enable(RCC_USART2);
}

static void
led_setup(void) {
    gpio_set_mode(LED_PORT, GPIO_MODE_OUTPUT_2_MHZ,
                 GPIO_CNF_OUTPUT_PUSHPULL, LED_PIN);
}

static void
button_setup(void) {
    gpio_set_mode(GPIOA, GPIO_MODE_INPUT,
                  GPIO_CNF_INPUT_FLOAT, GPIO0);
    gpio_set(BTN_PORT, BTN_PIN); // Подтяжка к питанию

    exti_select_source(EXTI0, BTN_PORT);
    exti_set_trigger(EXTI0, EXTI_TRIGGER_FALLING);
    exti_enable_request(EXTI0);
    nvic_enable_irq(NVIC_EXTI0_IRQ);
}

static void
uart_setup(void) {
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
                 GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO2);
    gpio_set_mode(GPIOA, GPIO_MODE_INPUT,
                 GPIO_CNF_INPUT_FLOAT, GPIO3);

    usart_set_baudrate(USART2, 115200);
    usart_set_databits(USART2, 8);
    usart_set_stopbits(USART2, USART_STOPBITS_1);
    usart_set_parity(USART2, USART_PARITY_NONE);
    usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
    usart_set_mode(USART2, USART_MODE_TX_RX);

    usart_enable_rx_interrupt(USART2);
    nvic_enable_irq(NVIC_USART2_IRQ);

    usart_enable(USART2);
}


void
exti0_isr(void) {
    exti_reset_request(EXTI0);
    usart_send_blocking(USART2, 'T');
}

void
usart2_isr(void) {
    if(usart_get_flag(USART2, USART_SR_RXNE)) {
        uint8_t data = usart_recv(USART2);
        gpio_toggle(LED_PORT, LED_PIN);
    }
}

int
main(void) {
    clock_setup();
    led_setup();
    button_setup();
    uart_setup();
    while(1) {
    }
}