#include "player.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Movimenta o jogador no labirinto
void move_player(Maze *maze, Player *player, char direction) {
    int new_x = player->x;
    int new_y = player->y;

    // Determina a nova posição com base no comando
    if (direction == 'w') new_x--;
    else if (direction == 's') new_x++;
    else if (direction == 'a') new_y--;
    else if (direction == 'd') new_y++;

    // Verifica se a nova posição está dentro dos limites
    if (new_x >= 0 && new_x < maze->rows && new_y >= 0 && new_y < maze->cols) {
        // Se não for uma parede
        if (maze->grid[new_x][new_y] != '#') {
            maze->grid[player->x][player->y] = ' '; // Deixa o espaço anterior vazio
            player->x = new_x;
            player->y = new_y;
            maze->grid[player->x][player->y] = '@'; // Atualiza a posição do jogador

            player->score--; // Reduz as jogadas restantes

            // Verifica se chegou à saída
            if (maze->grid[player->x][player->y] == 'E') {
                printf("Parabéns! Você venceu o jogo!\n");
                printf("Pontuação final: %d\n", player->score);
                exit(0);
            }
        }
    }
}
