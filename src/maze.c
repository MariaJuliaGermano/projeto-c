#include "maze.h"
#include <stdlib.h>
#include <stdio.h>

Maze *create_maze(int rows, int cols) {
    Maze *maze = malloc(sizeof(Maze));
    if (!maze) {
        printf("Erro: Falha ao alocar memória para o labirinto.\n");
        exit(1);
    }

    maze->rows = rows;
    maze->cols = cols;

    maze->grid = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        maze->grid[i] = malloc(cols * sizeof(char));
    }
    return maze;
}

void load_maze(Maze *maze) {
    char example[15][20] = {
        "####################",
        "#@       #     *   +",
        "###  #  ###  #### ##",
        "#   #   #         # ",
        "#   #######  ###### ",
        "#        #         #",
        "###  #########  ### ",
        "#   #      #       #",
        "#   ####   ##### ###",
        "#       #   #       ",
        "#####   ###   ######",
        "#                  #",
        "###  #########  ####",
        "#       #         E#",
        "####################"
    };

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            maze->grid[i][j] = example[i][j];
        }
    }
}

void draw_maze(Maze *maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            putchar(maze->grid[i][j]); // Exibe um caractere
        }
        putchar('\n'); // Nova linha
    }
}
