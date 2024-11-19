# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Source and object files
SRCS = src/main.c src/keyboard.c src/screen.c src/timer.c src/maze.c
OBJS = $(SRCS:.c=.o)

# Output binary
OUT = build/labirinto

# Build target
all: build $(OUT)

$(OUT): $(OBJS)
	@echo "Linking objects..."
	$(CC) -o $(OUT) $(OBJS) $(CFLAGS)

# Compile source files into object files
%.o: %.c
	@echo "Compiling $<..."
	$(CC) -c $< -o $@ $(CFLAGS)

# Create the build directory if it doesn't exist
build:
	@mkdir -p build

# Clean target
clean:
	@echo "Cleaning build files..."
	rm -f $(OBJS) $(OUT)
	rm -rf build

# Run target
run: all
	./$(OUT)
