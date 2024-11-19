#include "keyboard.h"
#include "screen.h"
#include "maze.h"
#include <stdio.h>

int main() {
    screenInit(1);       // Inicializa a tela com bordas
    keyboardInit();      // Inicializa o teclado

    Maze *maze = create_maze(13, 38); // Ajuste do tamanho
    Player player = {1, 1, 100};      // Inicializa o jogador
    load_maze(maze);                  // Carrega o layout do labirinto

    // Desenha o labirinto
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            screenGotoxy(j + 2, i + 3); // Ajusta para caber dentro das bordas
            putchar(maze->grid[i][j]);
        }
    }

    while (player.score > 0) {
        // Exibe informações no topo da tela
        screenGotoxy(2, 0); // Mais deslocado
        printf("Jogador: @ | Jogadas restantes: %d\n  (W, S, A, D) Para se mover (Enter para sair)", player.score);

        // Captura a entrada do jogador
        char key = readch();

        if (key == '\n') break;

        // Move o jogador com base na entrada
        move_player(maze, &player, key);

        player.score--;

        if (player.score <= 0) {
            screenClear();
            screenGotoxy(10, 5);
            printf("+----------------------------------+\n");
            printf("    |          GAME OVER               |\n");
            printf("    +----------------------------------+\n");
        
            readch();
        }
    }

    // Libera os recursos e restaura o terminal
    free_maze(maze);
    keyboardDestroy();
    screenShowCursor();
    screenDestroy();
    return 0;
}
