#ifndef MAZE_H
#define MAZE_H

typedef struct {
    int rows;
    int cols;
    char **grid; // Matriz do labirinto alocada dinamicamente
} Maze;

typedef struct {
    int x, y; // Posição do jogador
    int score; // Pontuação do jogador
} Player;

Maze *create_maze(int rows, int cols); // Cria o labirinto
void free_maze(Maze *maze); // Libera a memória do labirinto
void load_maze(Maze *maze); // Carrega ou gera o labirinto
void move_player(Maze *maze, Player *player, char direction); // Movimenta o jogador

#endif
