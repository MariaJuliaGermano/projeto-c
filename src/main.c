#include "keyboard.h"
#include "screen.h"
#include "maze.h"
#include <stdio.h>

int main() {
    Maze *maze = create_maze(15, 40); // Cria o labirinto 5x5
    Player player = {1, 1, 1000};     // Posição inicial do jogador e 10 jogadas restantes
    load_maze(maze);                // Carrega o layout inicial do labirinto

    while (player.score > 0) {
        clear_screen(); // Limpa a tela antes de redesenhar

        // Exibe o número de jogadas restantes
        printf("Jogadas restantes: %d\n", player.score);
        printf("Jogador: 🧍 | Jogadas restantes: %d\n", player.score);
        // Exibe o labirinto
        draw_maze(maze->grid, maze->rows, maze->cols);

        // Captura a entrada do jogador
        char key = get_key();
        move_player(maze, &player, key);

        // Atualiza as jogadas restantes
        player.score--;

        // Verifica se as jogadas acabaram
        if (player.score <= 0) {
            printf("Game Over! Você não tem mais jogadas, sua pontuação foi 0.\n");
            break;
        }
    }

    // Libera os recursos do labirinto
    free_maze(maze);

    return 0;
}
