#include "maze.h"
#include <stdlib.h>
#include <stdio.h>

Maze *create_maze(int rows, int cols) {
    Maze *maze = malloc(sizeof(Maze));
    maze->rows = rows;
    maze->cols = cols;
    maze->grid = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        maze->grid[i] = malloc(cols * sizeof(char));
    }
    return maze;
}

void free_maze(Maze *maze) {
    for (int i = 0; i < maze->rows; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

void load_maze(Maze *maze) {
    // Exemplo: Carregar um labirinto básico
    char example[10][10] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '@', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', ' ', 'E', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            maze->grid[i][j] = example[i][j];
        }
    }
}

void move_player(Maze *maze, Player *player, char direction) {
    int new_x = player->x;
    int new_y = player->y;

    if (direction == 'w') new_x--;
    else if (direction == 's') new_x++;
    else if (direction == 'a') new_y--;
    else if (direction == 'd') new_y++;

    if (maze->grid[new_x][new_y] == ' ' || maze->grid[new_x][new_y] == 'E') {
        maze->grid[player->x][player->y] = ' ';
        player->x = new_x;
        player->y = new_y;
        maze->grid[new_x][new_y] = '@';

        if (maze->grid[new_x][new_y] == 'E') {
            printf("Você venceu!\n");
            exit(0);
        }
    }
}
