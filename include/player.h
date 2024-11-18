#ifndef PLAYER_H
#define PLAYER_H

#include "maze.h" // Inclui a definição de Maze

typedef struct {
    int x, y;   // Posição do jogador
    int score;  // Pontuação (ou jogadas restantes)
} Player;

// Declaração da função para movimentar o jogador
void move_player(Maze *maze, Player *player, char direction);

#endif
