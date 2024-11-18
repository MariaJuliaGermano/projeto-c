#ifndef MAZE_H
#define MAZE_H

typedef struct Maze {
    int rows, cols; // Dimensões do labirinto
    char **grid;    // Matriz de caracteres
} Maze;

Maze *create_maze(int rows, int cols);
void load_maze(Maze *maze);
void draw_maze(Maze *maze);

#endif
