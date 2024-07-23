UNAME := $(shell uname)

GCC = gcc
GCC_FLAG = -Wall -pedantic -std=c99 -Wno-missing-braces
INC = -I ./inc/
ifeq ($(UNAME), Linux)
LINK = -L ./lib_unix -lraylib -lm
else
LINK = -L ./lib_win -lraylib -lopengl32 -lgdi32 -lwinmm -lm
endif
SRC = ./src/main.c
BUILD_PATH = ./build/snake_game

all:
	$(GCC) $(SRC) -o $(BUILD_PATH) $(GCC_FLAG) $(INC) $(LINK)

clean:
	rm $(BUILD_PATH)