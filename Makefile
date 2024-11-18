CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -pedantic
SRCS = src/main.c src/keyboard.c src/screen.c src/timer.c src/maze.c
OBJS = $(SRCS:.c=.o)
OUT = build/labirinto

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) -o $(OUT) $(OBJS) $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS) $(OUT)
	rm -rf build
