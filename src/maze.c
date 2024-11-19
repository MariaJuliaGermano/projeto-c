#include "maze.h"
#include "screen.h"
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
    char example[13][38] = {
        "=====================================",
        "|        |      |       |           |",
        "|== === === ===== === === ======= ==|",
        "|   |   |   |       |     |         |",
        "| ===== ===== ======= ===== ========|",
        "|       |       |         |      |  |",
        "|== === ===== ===== ======= === ====|",
        "|   | |       |     |     |   |     |",
        "| | === ======= |== | ===== === ====|",
        "| |         |   |   |   |       |   |",
        "| ===== === ===== ===== ======= ====|",
        "|     |   |         |     |        i|",
        "====================================="
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
    if (direction == 'w') new_x--;      // Move para cima
    else if (direction == 's') new_x++; // Move para baixo
    else if (direction == 'a') new_y--; // Move para a esquerda
    else if (direction == 'd') new_y++; // Move para a direita

    // Valida se a nova posição está dentro do labirinto
    if (new_x >= 0 && new_x < maze->rows && new_y >= 0 && new_y < maze->cols) {
        char target = maze->grid[new_x][new_y];

        if (target == ' ') { // Espaço vazio, movimento permitido
            // Apaga a posição antiga do jogador
            screenGotoxy(player->y + 2, player->x + 3); // +1 para alinhar ao terminal
            putchar(' ');

            // Atualiza a posição do jogador
            player->x = new_x;
            player->y = new_y;

            // Desenha o jogador na nova posição
            screenGotoxy(player->y + 2, player->x + 3);
            putchar('S');
        } else if (target == 'i') { // Objetivo alcançado
            screenClear();
            printf("+----------------------------------------+\n");
            printf("|   PARABÉNS!!!  Sua pontuação foi: %d  |\n", player->score);
            printf("+----------------------------------------+\n");
            exit(0);
        }
    }
}
