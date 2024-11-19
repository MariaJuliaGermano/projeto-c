#include "keyboard.h"
#include "screen.h"
#include "maze.h"
#include <stdio.h>

int main() {
    Maze *maze = create_maze(15, 40); // Cria o labirinto 5x5
    Player player = {1, 1, 100};     // Posição inicial do jogador e 10 jogadas restantes
    load_maze(maze);                // Carrega o layout inicial do labirinto

    while (player.score > 0) {
        clear_screen(); // Limpa a tela antes de redesenhar

        // Exibe o número de jogadas restantes
        printf("Jogador: 🧍 | Jogadas restantes: %d\n", player.score);
        printf("Pressione Enter para sair do jogo\n");

        // Exibe o labirinto
        draw_maze(maze->grid, maze->rows, maze->cols);

        // Captura a entrada do jogador
        char key = get_key();

        // Verifica se o jogador pressionou Enter
        if (key == '\n') {
            clear_screen();
            printf("Você pressionou Enter. O jogo foi encerrado.\n");
            break; // Sai do loop principal
        }

        // Processa o movimento do jogador
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
