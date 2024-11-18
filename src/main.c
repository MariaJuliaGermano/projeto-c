#include "maze.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

void clear_screen() {
    printf("\033[2J\033[H"); // Limpa a tela
}

int main() {
    Maze *maze = create_maze(15, 20);
    load_maze(maze);

    Player player = {1, 1, 100}; // Posição inicial (1,1) e 100 jogadas

    while (player.score > 0) {
        clear_screen();
        draw_maze(maze);

        printf("Jogador: @ | Jogadas restantes: %d\n", player.score);
        printf("Use W, A, S, D para mover: ");
        char command = getchar();
        getchar(); // Captura o Enter

        move_player(maze, &player, command);

        if (player.score <= 0) {
            printf("Game Over! Você ficou sem jogadas.\n");
        }
    }

    return 0;
}
