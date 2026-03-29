CC = gcc
CFLAGS = -g -O0 -Wall -Wextra
LDFLAGS = -lSDL3 -lm

SRCS = $(wildcard src/*.c src/**/*.c)
OBJS = $(patsubst src/%.c,build/%.o,$(SRCS))

build/game: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
