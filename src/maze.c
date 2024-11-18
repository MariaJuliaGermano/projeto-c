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
    char example[15][40] = {
        "#####################",
        "#@        #        *      +           #",
        "###  #  ###   ##   ####   ##   ##     #",
        "#   #   #   #       #     #           #",
        "#   ####   ### #####   ###            #",
        "#       #       #         *       #   #",
        "###   ##   ### #### ####             #",
        "#   #   #       #     #     #   #     #",
        "#   #   ###   #####   ##   #   ###    #",
        "#   #         #   #   #   #       #   #",
        "#   ###   ##   ###   ###   ###        #",
        "#     #    #         #     #          #",
        "###   ##   ####   ###   ###           #",
        "#        #        #        #    #    E#",
        "##################"
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

    // Calcula a nova posição com base na entrada do usuário
    if (direction == 'w') new_x--;
    else if (direction == 's') new_x++;
    else if (direction == 'a') new_y--;
    else if (direction == 'd') new_y++;

    // Verifica se o movimento é válido
    if (new_x >= 0 && new_x < maze->rows && new_y >= 0 && new_y < maze->cols) {
        char next_cell = maze->grid[new_x][new_y];

        // Só permite movimento em espaços vazios ou itens
        if (next_cell == ' ' || next_cell == '*' || next_cell == '+' || next_cell == 'E') {
            maze->grid[player->x][player->y] = ' '; // Remove o jogador da posição anterior
            player->x = new_x;
            player->y = new_y;
            maze->grid[player->x][player->y] = '@'; // Atualiza a nova posição do jogador
        }
    }
}
