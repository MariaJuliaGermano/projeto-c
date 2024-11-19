#include "maze.h"
#include "screen.h"
#include <stdlib.h>
#include <stdio.h>

void move_player(Maze *maze, Player *player, char direction) {
    int new_x = player->x;
    int new_y = player->y;

    // Calcula a nova posição com base na entrada do usuário
    if (direction == 'w') new_x--;
    else if (direction == 's') new_x++;
    else if (direction == 'a') new_y--;
    else if (direction == 'd') new_y++;

    // Verifica se o movimento é válido (não ultrapassa os limites)
    if (new_x >= 0 && new_x < maze->rows && new_y >= 0 && new_y < maze->cols) {
        // Se o jogador atingir a saída, o jogo termina
        if (maze->grid[new_x][new_y] == 'E') {
            screenClear();
            printf("+----------------------------------+\n");
            printf("|          PARABÉNS!!!             |\n");
            printf("|  SUA PONTUAÇÃO FINAL: %2d JOGADAS |\n", player->score);
            printf("+----------------------------------+\n");
            exit(0); // Sai do jogo imediatamente
        }

        // Atualiza a posição do jogador se for espaço vazio
        if (maze->grid[new_x][new_y] == ' ') {
            // Apaga o jogador da posição anterior
            screenGotoxy(player->y, player->x);
            putchar(' ');

            // Atualiza as coordenadas do jogador
            player->x = new_x;
            player->y = new_y;

            // Desenha o jogador na nova posição
            screenGotoxy(player->y, player->x);
            putchar('@');
        }
    }
}
