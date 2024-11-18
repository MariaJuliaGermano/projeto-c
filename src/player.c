#include "player.h"
#include <stdio.h>
#include <stdlib.h>

void move_player(Maze *maze, Player *player, char direction) {
    int new_x = player->x;
    int new_y = player->y;

    if (direction == 'w') new_x--;
    else if (direction == 's') new_x++;
    else if (direction == 'a') new_y--;
    else if (direction == 'd') new_y++;

    if (new_x >= 0 && new_x < maze->rows && new_y >= 0 && new_y < maze->cols) {
        if (maze->grid[new_x][new_y] != '#') {
            maze->grid[player->x][player->y] = ' '; // Limpa posição anterior
            player->x = new_x;
            player->y = new_y;
            maze->grid[player->x][player->y] = '@'; // Atualiza jogador

            player->score--; // Reduz jogadas restantes

            if (maze->grid[player->x][player->y] == 'E') {
                printf("Parabéns! Você venceu o jogo!\n");
                printf("Pontuação final: %d\n", player->score);
                exit(0);
            }
        }
    }
}
