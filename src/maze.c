#include "maze.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Cria e aloca memória para o labirinto
Maze *create_maze(int rows, int cols) {
    Maze *maze = malloc(sizeof(Maze));
    if (!maze) {
        printf("Erro: Falha ao alocar memória para o labirinto.\n");
        exit(1);
    }

    maze->rows = rows;
    maze->cols = cols;

    maze->grid = malloc(rows * sizeof(char *));
    if (!maze->grid) {
        printf("Erro: Falha ao alocar memória para as linhas do labirinto.\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        maze->grid[i] = malloc(cols * sizeof(char));
        if (!maze->grid[i]) {
            printf("Erro: Falha ao alocar memória para as colunas do labirinto.\n");
            exit(1);
        }
    }
    return maze;
}

// Carrega o layout do labirinto com caracteres ASCII
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

// Exibe o labirinto no terminal
void draw_maze(Maze *maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            putchar(maze->grid[i][j]); // Exibe diretamente o caractere
        }
        putchar('\n'); // Nova linha após cada linha do labirinto
    }
}