#include "keyboard.h"
#include "screen.h"
#include "maze.h"
#include <stdio.h>

int main() {
    screenInit(1);
    keyboardInit();

    Maze *maze = create_maze(15, 40);
    Player player = {1, 1, 100};
    load_maze(maze);

    // Desenha o labirinto inteiro apenas uma vez
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            screenGotoxy(j, i);
            putchar(maze->grid[i][j]);
        }
    }

    // Coloca o jogador na posição inicial
    screenGotoxy(player.y, player.x + 2);
    putchar('@');

    while (player.score > 0) {
        // Exibe informações no topo da tela
        screenGotoxy(0, 0); // Move para o canto superior esquerdo
        printf("Jogador: @ | Jogadas restantes: %d\n", player.score);
        printf("Use W, A, S, D para mover. Pressione Enter para sair.\n");
        printf("\n"); // Linha em branco para separar do labirinto

        // Captura a entrada do jogador
        char key = readch();

        // Verifica se o jogador pressionou Enter
        if (key == '\n') break;

        // Processa o movimento do jogador
        move_player(maze, &player, key);

        player.score--;

        // Verifica se o jogador perdeu
        if (player.score <= 0) {
            screenClear();
            printf("Game Over! Você ficou sem jogadas.\n");
            break;
        }
    }

    free_maze(maze);
    screenShowCursor();
    keyboardDestroy();
    screenDestroy();
    return 0;
}
