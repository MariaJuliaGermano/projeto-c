#include "maze.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Cria e aloca memória para o labirinto
Maze *create_maze(int rows, int cols) {
    Maze *maze = malloc(sizeof(Maze));
    maze->rows = rows;
    maze->cols = cols;
    maze->grid = malloc(rows * sizeof(char **));
    for (int i = 0; i < rows; i++) {
        maze->grid[i] = malloc(cols * sizeof(char *));
    }
    return maze;
}

// Carrega o layout do labirinto com emojis
void load_maze(Maze *maze) {
    char *example[15][20] = {
        {"🌲", "🌲", "🌲", "🌲", "🌲", "🌲", "🌲", "🌲", "🌲", "🌲",
         "🌲", "🌲", "🌲", "🌲", "🌲", "🌲", "🌲", "🌲", "🌲", "🌲"},
        {"🌲", "🧍", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "🌲",
         "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "🌲"},
        {"🌲", "🌲", "🌲", "  ", "🌲", "🌲", "🌲", "  ", "🌲", "🌲",
         "🌲", "🌲", "  ", "  ", "  ", "🌲", "🌲", "  ", "  ", "🌲"},
        {"🌲", "  ", "  ", "  ", "🌲", "  ", "  ", "  ", "  ", "  ",
         "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "🌲"},
        {"🌲", "  ", "🌲", "🌲", "🌲", "🌲", "🌲", "🌲", "  ", "🌲",
         "  ", "  ", "  ", "  ", "  ", "🌲", "🌲", "  ", "  ", "🌲"},
        {"🌲", "  ", "🌲", "  ", "  ", "  ", "  ", "  ", "  ", "🌲",
         "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "🌲"},
        {"🌲", "  ", "🌲", "🌲", "🌲", "🌲", "  ", "  ", "  ", "🌲",
         "🌲", "  ", "🌲", "🌲", "🌲", "🌲", "  ", "  ", "  ", "🌲"},
        {"🌲", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ",
         "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "🌲"},
        {"🌲", "🌲", "🌲", "  ", "  ", "  ", "  ", "  ", "  ", "  ",
         "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "🌲"},
        {"🌲", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ",
         "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "🏁"}
    };

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            maze->grid[i][j] = strdup(example[i][j]); // Copia cada emoji para a matriz
        }
    }
}

// Exibe o labirinto no terminal
void draw_maze(Maze *maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%s", maze->grid[i][j]); // Exibe os emojis diretamente
        }
        putchar('\n'); // Quebra de linha
    }
}