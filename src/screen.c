#include "screen.h"
#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H"); // Sequência ANSI para limpar a tela e mover o cursor para o topo
}

void draw_maze(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == '#') {
                printf("\033[37m#\033[0m"); // Cinza para paredes
            } else if (maze[i][j] == '@') {
                printf("\033[33m@\033[0m"); // Amarelo para o jogador
            } else if (maze[i][j] == 'E') {
                printf("\033[32m🏁\033[0m"); // Verde para a saída
            } else {
                putchar(maze[i][j]); // Qualquer outro símbolo
            }
        }
        putchar('\n');
    }
}

