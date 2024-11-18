# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -g
OBJDIR = build
SRCDIR = src
INCDIR = include

# Arquivos do projeto
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/maze.c $(SRCDIR)/player.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/maze.o $(OBJDIR)/player.o
EXEC = $(OBJDIR)/labirinto

# Alvo padrão
all: $(EXEC)

# Linkagem final
$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilação dos arquivos .c para .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -rf $(OBJDIR)
