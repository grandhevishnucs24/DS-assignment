CC=gcc
CFLAGS=-Wall -Wextra -std=c11
BIN_DIR=bin

SRCS := $(shell find . -name '*.c')
BINS := $(patsubst ./%.c, $(BIN_DIR)/%, $(SRCS))

all: $(BIN_DIR) $(BINS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BIN_DIR) a.out

.PHONY: all clean
