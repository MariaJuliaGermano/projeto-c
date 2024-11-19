#include "keyboard.h"
#include "screen.h"
#include "maze.h"
#include <stdio.h>

int main() {
    screenInit(1);       
    keyboardInit();     
    Maze *maze = create_maze(13, 38); 
    Player player = {1, 1, 99};     
    load_maze(maze);                  

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            screenGotoxy(j + 2, i + 3); 
            putchar(maze->grid[i][j]);
        }
    }

    while (player.score > 0) {
        screenGotoxy(2, 0); 
        printf("Jogador: S | Jogadas restantes: %d  \n  (W, S, A, D) Para se mover (Enter para sair)", player.score);

        char key = readch();

        if (key == '\n') break;

        move_player(maze, &player, key);

        player.score -= 1;

        if (player.score <= 0) {
            screenClear();
            screenGotoxy(10, 5);
            printf("          GAME OVER              \n");
        
            readch();
        }
    }

    free_maze(maze);
    keyboardDestroy();
    screenShowCursor();
    screenDestroy();
    return 0;
}
