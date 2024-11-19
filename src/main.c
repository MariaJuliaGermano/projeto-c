#include "keyboard.h"
#include "screen.h"
#include "maze.h"
#include <stdio.h>

int main() {
    screenInit(1);       // Inicializa a tela com bordas
    keyboardInit();      // Inicializa o teclado

    Maze *maze = create_maze(15, 40); // Cria o labirinto
    Player player = {1, 1, 100};      // Inicializa o jogador
    load_maze(maze);                  // Carrega o layout do labirinto

    // Desenha o labirinto inteiro apenas uma vez
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            screenGotoxy(j, i + 2); // Desloca o labirinto para baixo
            putchar(maze->grid[i][j]);
        }
    }

    // Posiciona o jogador no labirinto
    screenGotoxy(player.y + 2, player.x);
    putchar('@');

    while (player.score > 0) {
        // Exibe informações no topo da tela, fora da borda
        screenGotoxy(1, 0); // Linha 0 para o cabeçalho
        printf("Jogador: @ | Jogadas restantes: %d\n", player.score);
        screenGotoxy(1, 1); // Linha 1 para instruções
        printf("Use W, A, S, D para mover. Pressione Enter para sair.\n");

        // Captura a entrada do jogador
        char key = readch();

        if (key == '\n') break;

        move_player(maze, &player, key);

        player.score--;

        if (player.score <= 0) {
            screenClear();
            printf("+-----------------------------------+\n");
            printf("| GAME OVER, Você ficou sem jogadas |\n");
            printf("+-----------------------------------+\n");
            break;
        }
    }

    // Libera os recursos e restaura o terminal
    free_maze(maze);
    screenShowCursor();  // Reexibe o cursor
    keyboardDestroy();   // Restaura o teclado
    screenDestroy();     // Restaura o terminal
    return 0;
}
