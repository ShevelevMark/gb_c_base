CC := gcc
CFLAGS := -O2 -Wall -std=c11
SRC := $(wildcard ./src/*.c)
BIN := $(patsubst ./src/%.c, ./bin/%, $(SRC))

all: $(BIN)

./bin/%: ./src/%.c
	gcc $^ -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm ./bin/* 