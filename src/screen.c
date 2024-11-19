#include "screen.h"

void clear_screen() {
    screenInit(1); // Usa CLI-lib para limpar e configurar a tela
}

void draw_maze(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == '@') {
                screenSetColor(2, 0); // Jogador em verde
            } else if (maze[i][j] == 'E') {
                screenSetColor(1, 0); // Saída em vermelho
            } else if (maze[i][j] == '#') {
                screenSetColor(0, 7); // Paredes em preto com fundo cinza
            } else {
                screenSetColor(7, 0); // Caminho padrão em branco
            }
            putchar(maze[i][j]);
        }
        putchar('\n');
    }
    screenSetColor(7, 0); // Reseta para branco padrão
}
