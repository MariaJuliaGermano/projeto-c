#include "screen.h"
#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H"); // Sequência ANSI para limpar a tela e mover o cursor para o topo
}

void draw_maze(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char cell = maze[i][j];
            if (cell == '#') {
                printf("\033[37m🌲\033[0m"); // Parede
            } else if (cell == '@') {
                printf("\033[33m🧍\033[0m"); // Jogador
            } else if (cell == 'E') {
                printf("\033[32m🏁\033[0m"); // Saída
            } else if (cell == '*') {
                printf("\033[31m🌵\033[0m"); // Armadilha
            } else if (cell == '+') {
                printf("\033[34m🍎\033[0m"); // Bônus
            } else {
                putchar(' '); // Espaços vazios
            }
        }
        putchar('\n');
    }
}

