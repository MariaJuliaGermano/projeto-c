#include "screen.h"
#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H"); // Sequência ANSI para limpar a tela
}

void draw_maze(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            putchar(maze[i][j]); // Exibe cada caractere do labirinto
        }
        putchar('\n'); // Quebra de linha após cada linha do labirinto
    }
}
