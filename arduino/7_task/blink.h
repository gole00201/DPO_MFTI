#ifndef BLINK
#define BLINK

#include <avr/io.h>
#include "stddef.h"
#include <util/delay.h>

void blink(void);
void blink_twice(void);
void blink_thrice(void);

#endif