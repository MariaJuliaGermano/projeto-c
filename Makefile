CC = gcc
CFLAGS = -Iinclude
LDFLAGS = -Llib -lcli_lib  
SOURCES = src/main.c src/game.c
OBJECTS = $(SOURCES:.c=.o)
EXEC = build/jogo

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(EXEC)
