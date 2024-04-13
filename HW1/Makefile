CC = gcc
CFLAGS = -Wall -g
SRCS := $(wildcard *.c)
EXES := $(SRCS:.c=)


all: $(EXES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXES)
