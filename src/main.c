#include "keyboard.h"
#include "screen.h"
#include "timer.h"
#include "maze.h"
#include <stdio.h>

int main() {
    Maze *maze = create_maze(5, 5); // Cria o labirinto 5x5
    Player player = {1, 1, 100};    // Posição inicial do jogador e pontuação
    load_maze(maze);                // Carrega o layout inicial do labirinto

    Timer timer;
    start_timer(&timer); // Inicia o temporizador

    while (1) {
        clear_screen(); // Limpa a tela antes de redesenhar

        // Calcula e exibe o tempo restante
        int elapsed_time = get_elapsed_time(&timer);
        int time_limit = 30; // Limite de 30 segundos
        int time_left = time_limit - elapsed_time;
        printf("Tempo restante: %d segundos\n", time_left);

        // Verifica se o tempo acabou
        if (time_left <= 0) {
            printf("Tempo esgotado! Game Over.\n");
            break;
        }

        // Exibe o labirinto
        draw_maze(maze->grid, maze->rows, maze->cols);

        // Captura a entrada do jogador
        char key = get_key();
        move_player(maze, &player, key);

        // Atualiza a pontuação
        player.score--;
        if (player.score <= 0) {
            printf("Game Over! Você perdeu todos os pontos.\n");
            break;
        }
    }

    // Libera os recursos do labirinto
    free_maze(maze);

    return 0;
}
