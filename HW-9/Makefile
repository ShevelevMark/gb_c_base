CC := gcc
CFLAGS := -O2 -Wall -std=c11
SRC := $(wildcard ./src/*.c)
BIN := $(patsubst ./src/%.c, ./bin/%, $(SRC))

all: $(BIN)

./bin/%: ./src/%.c ./src/test/test.%.c
	gcc $^ -o $@ $(CFLAGS)
