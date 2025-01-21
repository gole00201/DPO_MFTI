/**
 * @file blink_exti.c
 * @author Volkov Egor (gole00201@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-01-14
 * @copyright Copyright (c) 2025
 */

#include <libopencm3/stm32/exti.h>
#include <libopencm3/cm3/nvic.h>
#include "gpio_init.h"

static void
exti_setup(void){
	rcc_periph_clock_enable(RCC_AFIO);
    nvic_enable_irq(NVIC_EXTI0_IRQ);
    exti_select_source(EXTI0, GPIOA);
	exti_set_trigger(EXTI0, EXTI_TRIGGER_BOTH);
	exti_enable_request(EXTI0);
}

int
main(void){
    gpio_setup();
    exti_setup();
    while(1){
        __asm volatile("nop");
    }
    return 0; // Houston, we have a problem =)
}