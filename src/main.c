#include "keyboard.h"
#include "screen.h"
#include "maze.h"

int main() {
    screenInit(1); // Inicializa a tela
    keyboardInit(); // Inicializa o teclado

    Maze *maze = create_maze(15, 40);
    Player player = {1, 1, 100};
    load_maze(maze);

    while (player.score > 0) {
        clear_screen();
        draw_maze(maze->grid, maze->rows, maze->cols);

        char key = get_key();
        if (key == '\n') break;

        move_player(maze, &player, key);
        player.score--;
    }

    free_maze(maze);

    keyboardDestroy(); // Destrói configurações do teclado
    screenDestroy();   // Reseta a tela ao padrão

    return 0;
}
