#include "player.h"
#include <stdio.h>
#include <string.h> // Para comparar strings (strcmp)

// Implementação da lógica de movimentação
void move_player(Maze *maze, Player *player, char direction) {
    int new_x = player->x;
    int new_y = player->y;

    // Determina a nova posição com base na tecla pressionada
    if (direction == 'w') new_x--;
    else if (direction == 's') new_x++;
    else if (direction == 'a') new_y--;
    else if (direction == 'd') new_y++;

    // Verifica se a nova posição está dentro do labirinto
    if (new_x >= 0 && new_x < maze->rows && new_y >= 0 && new_y < maze->cols) {
        // Se o próximo espaço não for uma parede
        if (strcmp(maze->grid[new_x][new_y], "🌲") != 0) {
            maze->grid[player->x][player->y] = "  ";  // Deixa o espaço anterior vazio
            player->x = new_x;                       // Atualiza a posição do jogador
            player->y = new_y;
            maze->grid[player->x][player->y] = "🧍";  // Coloca o jogador na nova posição

            // Reduz a pontuação (jogadas restantes)
            player->score--;

            // Verifica se o jogador alcançou a saída
            if (strcmp(maze->grid[player->x][player->y], "🏁") == 0) {
                printf("Parabéns! Você venceu o jogo!\n");
                printf("Pontuação final: %d\n", player->score);
                exit(0); // Termina o jogo
            }
        }
    }
}
