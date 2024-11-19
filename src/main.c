#include "keyboard.h"
#include "screen.h"
#include "maze.h"
#include "timer.h"
#include <stdio.h>

int main() {
    screenInit(1);
    keyboardInit();
    timerInit(1000);

    Maze *maze = create_maze(15, 40);
    Player player = {1, 1, 100};
    load_maze(maze);

    while (player.score > 0) {
        screenClear();
        printf("Jogador: @ | Jogadas restantes: %d\n", player.score);

        for (int i = 0; i < maze->rows; i++) {
            for (int j = 0; j < maze->cols; j++) {
                putchar(maze->grid[i][j]);
            }
            putchar('\n');
        }

        if (timerTimeOver()) {
            char key = readch();
            if (key == '\n') break;
            move_player(maze, &player, key);
            player.score--;
        }
    }

    free_maze(maze);
    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}
