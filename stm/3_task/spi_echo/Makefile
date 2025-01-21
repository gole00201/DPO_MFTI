PROJECT = blink_exti
BUILD_DIR = bin

SHARED_DIR = ../common
CFILES = spi_echo.c


DEVICE=stm32f103c8t6
OOCD_INTERFACE=stlink
OOCD_TARGET=stm32f1x
OOCD_FILE=
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
# TODO Поменяйте
OPENCM3_DIR=../../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
