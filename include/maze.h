#ifndef MAZE_H
#define MAZE_H

typedef struct {
    int rows;
    int cols;
    char **grid; 
} Maze;

typedef struct {
    int x, y; 
    int score; 
} Player;

Maze *create_maze(int rows, int cols); 
void free_maze(Maze *maze); 
void load_maze(Maze *maze); 
void move_player(Maze *maze, Player *player, char direction); 

#endif
