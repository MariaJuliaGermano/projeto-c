CC = gcc
CFLAGS = -Iinclude
SRCS = src/main.c src/keyboard.c src/screen.c src/timer.c
OBJS = $(SRCS:.c=.o)
OUT = build/labirinto

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) -o $(OUT) $(OBJS) $(CFLAGS)

clean:
	rm -f $(OBJS) $(OUT)
