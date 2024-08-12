GCC = gcc
GCC_FLAG = -Wall -pedantic -std=c99 -Wno-missing-braces
INC = -I ./inc/
SRC = ./src/main.c
BUILD_PATH = ./build/snake_game

# -----------------------------------------------------------
ifeq ($(ARCH), unix)
LINK = -L ./lib/lib_unix -lraylib -lm -pthread -ldl
endif
ifeq ($(ARCH), win86)
LINK = -L ./lib/lib_win/x86 -lraylib -lopengl32 -lgdi32 -lwinmm -lm
endif
ifeq ($(ARCH), win64)
LINK = -L ./lib/lib_win/x64 -lraylib -lopengl32 -lgdi32 -lwinmm -lm
endif # ARCH
# -----------------------------------------------------------

all:
	$(GCC) $(SRC) -o $(BUILD_PATH) $(GCC_FLAG) $(INC) $(LINK)