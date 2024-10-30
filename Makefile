CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/main.c src/game.c
OUT = build/jogo

all: $(SRC)
    $(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
    rm -f $(OUT)
